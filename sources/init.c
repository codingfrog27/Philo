/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 12:31:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/02/07 14:56:17 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_philo	*philo_init(t_data	*data)
{
	int				i;
	t_philo			*philos;

	i = 0;
	philos = malloc(sizeof(t_philo) * data->philo_amount);
	if (!philos)
		return (NULL);
	while (i < data->philo_amount)
	{
		philos[i].id = i;
		philos[i].meals_eaten = 0;
		philos[i].full = false;
		philos[i].last_mealtime = 0;
		// not sure if ^ should be 0 or local time
		philos[i].data = data;
		i++;
	}
	return (philos);
}

// So I am setting of the right fork before initing the mutex, but that shouldnt
// be and issue since the adress of the mutex does already exist and it doesnt
// change upon initing, right?
bool	setting_the_table(t_data *data)
{
	int				i;
	pthread_mutex_t	*meal_check;

	data->philos = philo_init(data);
	meal_check = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	 //change to 1 mutex in data?
	//could just use normal mutexes instead of ptrs?
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	if (!data->philos || !meal_check || !data->forks)
		return (false);
	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_init(&meal_check[i], NULL) != 0 \
		|| pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (false);
		data->philos[i].meal_check = &meal_check[i];
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[i + 1];
		i++;
	}
	data->philos[i - 1].right_fork = &data->forks[0];
	return (true);
}

bool	starting_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_lock(data->philos[i].meal_check) != 0 || \
		pthread_create(&data->philos->thread, NULL, &philo_routine, \
		(void *)&data->philos[i]) != 0)
			return (false); //should be free function?
				// could make it return i to see how many threads i should free
		i++;
	}
	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_unlock(data->philos[i].meal_check) != 0)
			return (false);
		i++;
	}
	// might change to 1 mutex instead of 1mutex per philo
	data->all_alive = true; //could move to init or parsing, but can also be check for thread creation :)
	time_since_x(0);
	return (true);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 18:23:54 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/20 19:51:46 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(void)
{
	//to be made
}

void	*philo(void *para)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = para;
	printf("hi, Im philo nb %d\n", philo->id);
	coolsleep(50000);
	while (1 < 5)
	{
		i++;
		//eat
		//sleep
		//think
	}
}

//grab fork func
//^- lock-> check avail -> if yes eat -> else usleep 30 - 1000 ms)

//mutex lock protect print, dont do much else

//release fork function

//void create threads

bool	setting_the_table(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->philo_amount);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	i = 0;
	while (i < data->philo_amount)
	{
		data->philos[i].id = i;
		pthread_create(&data->philos->thread, NULL, philo, &data->philos[i]);
		i++;
	}

	//malloc check?
	return (true);
}

void	monitoring(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = data->philos;
	while (1)
	{
		while (i < data->philo_amount)
		{
			pthread_mutex_lock(&philos[i].meal_check);
			if (time_since_x(philos[i].last_mealtime) > data->die_time)
				end_simulation();
			pthread_mutex_lock(&philos[i].meal_check);
			i++;
		}
		coolsleep(250); //random nbr atm
	}

}

int	main(int argc, char **argv)
{
	t_data		data;

	if (!parsing(argc, argv, &data))
	{
		printf("wrong input buddy");
		//might need a specefic error msg for this??
		return (1);
	}
	setting_the_table(&data);
	//1 philo might be edgecase that needs hardcoding
	return (0);
}

// 1 malloc a thread per philo + a mutex per fork
// (and maybe 1 for printing/monitoring?)
//  (A also had a mutex called ego?)


//
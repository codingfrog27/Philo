/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 18:23:54 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/23 18:17:26 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation()
{
	printf("bye byeee\n");
	exit(1);
}

bool	dinner_time(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_amount)
	{
		if (pthread_mutex_lock(data->philos[i].meal_check) != 0 || \
		pthread_create(&data->philos->thread, NULL, &philo, \
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
	return (true);
}
//grab fork func
//^- lock-> check avail -> if yes eat -> else usleep 30 - 1000 ms)

//mutex lock protect print, dont do much else

//release fork function

//void create threads

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
			pthread_mutex_lock(philos[i].meal_check);
			pthread_mutex_lock(philos[i].meal_check);
			if (time_since_x(philos[i].last_mealtime) > data->die_time)
			{
				philos[i].alive = false;
				end_simulation();
			}
			pthread_mutex_unlock(philos[i].meal_check);
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
	if (setting_the_table(&data) && dinner_time(&data))
		monitoring(&data);
	//1 philo might be edgecase that needs hardcoding
	return (0);
}

// 1 malloc a thread per philo + a mutex per fork
// (and maybe 1 for printing/monitoring?)
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 18:23:54 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/02/07 15:05:12 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_simulation(t_philo *philo)
{
	printf("philo %i died, their last mealtime was %lu \
	rest in pepperoni \n bye byeee\n", philo->id, philo->last_mealtime);
	exit(1);
}

void	monitoring(t_data *data)
{
	int		i;
	t_philo	*philos;
	long	last_mealtime;

	i = 0;
	philos = data->philos;
	while (1)
	{
		while (i < data->philo_amount)
		{
			pthread_mutex_lock(philos[i].meal_check);
			last_mealtime = philos[i].last_mealtime;
			pthread_mutex_unlock(philos[i].meal_check);
			if (last_mealtime > data->die_time)
			{
				printf("C_RED LAST MEALTIME WAS %lu but die time is %i", \
				last_mealtime, data->die_time);
				pthread_mutex_lock(&data->living_mutex);
				data->all_alive = false;
				if (data->full_philos >= data->philo_amount)
				{
					printf("%sEVERYONE FULL\n", C_LBLUE);
					exit(0);
				}
				end_simulation(&philos[i]);
				pthread_mutex_unlock(&data->living_mutex);
			}
			pthread_mutex_unlock(philos[i].meal_check);
			i++;
		}
		i = 0;
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
	if (setting_the_table(&data) && starting_threads(&data))
		monitoring(&data);
	//1 philo might be edgecase that needs hardcoding
	return (0);
}

// 1 malloc a thread per philo + a mutex per fork
// (and maybe 1 for printing/monitoring?)
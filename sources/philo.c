/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 17:14:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/02/13 20:17:05 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	coolsleep(philo->data->sleep_time);
	// printf("%sphilo %i slept at %li > %i %s\n", C_ORANGE, \
	// 	philo->id, time_since_x(whattimeisitrightnow), C_RESET);
	(void)philo;
}

void	repeat(t_philo *philo)
{
	// printf("spin, and do it all over again\n");
	(void)philo;
}

bool	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->meal_check);
	if (time_since_x(philo->last_mealtime) > data->die_time)
	{
		printf("%sphilo %i died here\nlast mealtime = %li > %i %s\n", C_ORANGE, \
		philo->id, time_since_x(philo->last_mealtime), data->die_time, C_RESET);
		pthread_mutex_lock(&data->living_mutex); //mutex lock protect??
		data->all_alive = false;
		pthread_mutex_unlock(&data->living_mutex);
		return (false);
	}
	pthread_mutex_lock(&data->living_mutex);
	if (data->all_alive == true)
	{
//but what if he dies in this small meantime??
//  Also maybe store last mealtime instead of calling time since x twice
		philo->last_mealtime = time_since_x(philo->last_mealtime);
		printf("%s philo %i a yummy meal at %lu %s:)\n", C_GREEN, philo->id, \
		philo->last_mealtime, C_RESET);
		philo->meals_eaten++;
		if (philo->meals_eaten == philo->data->meals_needed)
			data->full_philos++;
	}
	pthread_mutex_unlock(&data->living_mutex);
	pthread_mutex_unlock(philo->meal_check);
	return (true);
}

void	*philo_routine(void *para)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = para;
	pthread_mutex_lock(philo->meal_check);
	pthread_mutex_unlock(philo->meal_check);
	// if (philo->id % 2)
	// 	coolsleep(250);
	printf("hi, Im philo nb %d\n", philo->id);
	while (1)
	{
		eat(philo);
		philo_sleep(philo);
		repeat(philo);
	}
}

//grab fork func
//^- lock-> check avail -> if yes eat -> else usleep 30 - 1000 ms)

//mutex lock protect print, dont do much else

//release fork function
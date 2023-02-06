/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 17:14:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/02/06 19:38:36 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_sleep(t_philo *philo)
{
	printf("zzzzz\n");
	(void)philo;
}

void	repeat(t_philo *philo)
{
	printf("spin, and do it all over again\n");
	(void)philo;
}

bool	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(philo->meal_check);
	if (time_since_x(philo->last_mealtime) > data->die_time)
	{
		pthread_mutex_lock(&data->living_mutex); //mutex lock protect??
		data->all_alive = false;
		pthread_mutex_unlock(&data->living_mutex);
		return (false);
	}
	pthread_mutex_lock(&data->living_mutex);
	if (data->all_alive == true)
	{
		//but what if he dies in this small meantime?? Also maybe store last mealtime instead of calling time since x twice
		philo->last_mealtime = time_since_x(data->start_time);
		printf("philo %i a yummy meal at %lu :)\n", philo->id, \
		philo->last_mealtime);
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
	printf("hi, Im philo nb %d\n", philo->id);
	if (philo->id % 2)
		coolsleep(500);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 17:14:11 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/23 18:06:11 by mde-cloe      ########   odam.nl         */
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
	printf("yummy meal :)\n");
	philo->last_mealtime = time_since_x(data->start_time);
	pthread_mutex_unlock(philo->meal_check);
	return (true);
}

void	*philo(void *para)
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

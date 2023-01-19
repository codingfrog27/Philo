/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 18:02:24 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/19 19:48:28 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

long	whattimeisitrightnow(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	time_since_start(long start)
{
	return (whattimeisitrightnow() - start);
}

void	coolsleep(useconds_t sleep_time)
{
	long		start_time;
	long		time_passed;
	useconds_t	nap_time;
	//useconds is just an unsigned int?

	//still needs to be tested, idk if the all the values of usleep and the
	// time functions translate properly

	start_time = whattimeisitrightnow();
	time_passed = 0;
	nap_time = sleep_time / 100;
	while (time_passed < sleep_time)
	{
		usleep(nap_time);
		time_passed = time_since_start(start_time);
	}
}
// could be made into one function with a passed bool maybe, but like this I
// also think it's fine

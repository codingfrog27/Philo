/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:55:20 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/20 19:42:58 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

typedef struct philo
{
	int				id;
	int				meals_eaten;
	pthread_mutex_t	meal_check;
	long			last_mealtime;
	bool			alive;
	void			*data;
	pthread_t		thread;
}				t_philo;

typedef struct data
{
	int				philo_amount;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long			start_time;
	bool			finish_when_full;
	int				meals_needed;
	bool			*fork_ok; //?
	pthread_mutex_t	*forks;
	t_philo			*philos;
}				t_data;


bool	parsing(int argc, char **argv, t_data *data);


//time
long	time_since_x(long start);
long	whattimeisitrightnow(void);
bool	coolsleep(useconds_t sleep_time);
#endif // !PHILO_H
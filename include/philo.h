/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:55:20 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/02/07 14:59:51 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "h_colors.h"
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	bool			full;
	pthread_mutex_t	*meal_check;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_mealtime;
	t_data			*data;
	pthread_t		thread;
}				t_philo;
//also using mealcheck to see if philo is alive + as start lock?
struct s_data
{
	int				philo_amount;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long			start_time;
	pthread_mutex_t	living_mutex;
	bool			all_alive;
	bool			finish_when_full;
	int				meals_needed;
	int				full_philos;
	pthread_mutex_t	*forks;
	t_philo			*philos;
};

bool	parsing(int argc, char **argv, t_data *data);
bool	setting_the_table(t_data *data);
bool	starting_threads(t_data *data);
void	*philo_routine(void *para);

//time
long	time_since_x(long start);
long	whattimeisitrightnow(void);
bool	coolsleep(useconds_t sleep_time);
#endif // !PHILO_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 12:55:20 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/16 19:08:28 by mde-cloe      ########   odam.nl         */
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

typedef struct data
{
	int				philo_amount;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	long			start_time;
	bool			finish_when_full;
	int				meals_needed;
	bool			*fork_ok;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct philo
{
	int				philo_nbr;
	int				meals_eaten;
	long			last_mealtime;
	bool			alive;
	struct t_data	*data;

}				t_philo;

bool	parsing(int argc, char **argv, t_data *data);
#endif // !PHILO_H
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 18:23:54 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/19 20:02:51 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *para)
{
	while (1)
	{
		//eat
		//sleep
		//think
	}
	(void)para;
}

//grab fork func
//^- lock-> check avail -> if yes eat -> else usleep 30 - 1000 ms)

//mutex lock protect print, dont do much else

//release fork function

//void create threads

bool	setting_the_table(t_data *data)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * data->philo_amount);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_amount);
	//malloc check?
	return (true);
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

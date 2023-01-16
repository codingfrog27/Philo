/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/09 18:23:54 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/16 21:31:33 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *para)
{
	while (//philo alive?)
	{
		//eat
		//sleep
		//think
	}
}

void	info

mutex lock()
bool forkavailble;
//grab fork func
//^- lock-> check avail -> if yes eat -> else usleep 30 - 1000 ms)

//mutex lock protect print, dont do much else

//release fork function

//void create threads




int	main(int argc, char **argv)
{
	t_data	data;


	if (!parsing(argc, argv, &data))
	{
		printf("wrong input buddy");
		//might need a specefic error msg for this??
		return (1);
	}
	//1 philo might be edgecase that needs hardcoding
	return (0);
}

// 1 malloc a thread per philo + a mutex per fork (and maybe 1 for printing?)
//  (A also had a mutex called ego?)
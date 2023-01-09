/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 18:38:49 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/09 17:29:22 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*double_on_heap(void *para_nbr)
{
	int	*nbr;

	nbr = malloc(sizeof(int));
	printf("passed through var = %d\n", *(int *)para_nbr);
	*nbr = *(int *)para_nbr * 2;
	return ((void *)nbr);
}

int	main(int argc, char **argv)
{
	pthread_t		cool;
	int				nbr;
	int				*ret;
	pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	nbr = 5;
	pthread_create(&cool, NULL, double_on_heap, (void *)&nbr);
	pthread_join(cool, (void *)&ret);
	printf("doubled and heap var = %d\n", *ret);
	return (0);
}

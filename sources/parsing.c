/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mde-cloe <mde-cloe@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 17:40:45 by mde-cloe      #+#    #+#                 */
/*   Updated: 2023/01/23 12:32:28 by mde-cloe      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief just a small atoi for philo (libft not allowed)
 * since only positive nbrs are allowed for input >0 can be error return
 * @param str
 * @return converted int
 */
static int	philatoi(char *str)
{
	long	ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i])
	{
		ret = (ret * 10) + (str[i] - '0');
		if (str[i] < '0' || str[i] > '9' || ret > INT_MAX)
			return (-1);
		i++;
	}
	return ((int)ret);
}

bool	parsing(int argc, char **argv, t_data *data)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (false);
	i = 1;
	data->philo_amount = philatoi(argv[i++]);
	data->die_time = philatoi(argv[i++]);
	data->eat_time = philatoi(argv[i++]);
	data->sleep_time = philatoi(argv[i++]);
	if (argc == 6)
	{
		data->finish_when_full = true;
		data->meals_needed = philatoi(argv[i]);
	}
	else
	{
		data->finish_when_full = false;
		data->meals_needed = 1;
	}
	if (data->philo_amount <= 0 || data->die_time <= 0 || data->eat_time <= 0 \
		|| data->sleep_time <= 0 || data->meals_needed <= 0)
		return (false);
	return (true);
}

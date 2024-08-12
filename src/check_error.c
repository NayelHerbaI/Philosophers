/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:38:53 by naherbal          #+#    #+#             */
/*   Updated: 2024/03/05 16:55:33 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	check_error(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (printf("Not enough or too much arguments\n"));
	if (check_numbers(ac, av) == 1)
		return (printf("Arguments have to be digits only\n"));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (printf("Number of philosopher has to be between 1 and 200\n"));
	return (0);
}

int	check_numbers(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	is_dead(t_data *data, int i)
{
	pthread_mutex_lock(&data->lock);
	if (get_time() - data->philos[i].last_meal > (size_t)data->t_death)
	{
		message(&data->philos[i], "died");
		data->dead = 1;
	}
	pthread_mutex_unlock(&data->lock);
	usleep(100);
}

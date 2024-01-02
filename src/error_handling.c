/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:53:33 by naherbal          #+#    #+#             */
/*   Updated: 2023/11/28 13:29:30 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	error_handling(int ac, char **av)
{
	if (ac < 5)
		return (ft_putstr("Not enough arguments\n"));
	if (ac > 6)
		return (ft_putstr("Too much arguments\n"));
	if (is_num(av) == 1)
		return (ft_putstr("Arguments are not only digits or negative numbers\n"));
	if (ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
		return (ft_putstr("Number of philosophers has to be between 1 and 200\n"));
	return (0);
}

int	is_num(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		if (ft_atoi(av[i++]) < 0)
			return (1);
	}
	return (0);
}

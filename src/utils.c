/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:55:54 by naherbal          #+#    #+#             */
/*   Updated: 2024/03/05 16:56:45 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	my_sleep(t_data *data, int t_death)
{
	size_t	time;

	time = get_time();
	while (data->dead != 1)
	{
		if (get_time() - time >= t_death)
			break ;
		usleep(100);
	}
}

void	message(t_philo *philo, char *msg)
{
	size_t	time;

	time = get_time() - philo->data->s_time;
	pthread_mutex_lock(&philo->data->write);
	if (philo->data->finished != 1 && philo->data->dead != 1)
	{
		printf("%ld %d %s\n", time, philo->nb, msg);
	}
	pthread_mutex_unlock(&philo->data->write);
}

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - 48) + res * 10;
		i++;
	}
	return (res * sign);
}

void	death(t_data *data)
{
	int	i;

	while (data->finished != 1 || data->dead != 1)
	{
		i = 0;
		while (i < data->n_philo && data->dead != 1)
		{
			is_dead(data, i);
			i++;
		}
		if (data->dead == 1)
			break ;
		i = 0;
		while (data->n_meals != -1 && data->philos[i].count >= data->n_meals
			&& i < data->n_philo)
			i++;
		if (i == data->n_philo)
			data->finished = 1;
	}
}

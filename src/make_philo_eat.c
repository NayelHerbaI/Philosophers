/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nake_philo_eat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:21:13 by naherbal          #+#    #+#             */
/*   Updated: 2023/11/28 16:44:45 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*make_philo_eat(void *void_data)
{
	t_philo *curr;
	t_data	*data;

	data = (t_data *)void_data;
	curr = data->curr;
	pthread_mutex_lock(&curr->mutex);
	curr->fork = 2;
	if (curr->next != NULL)
		curr->next->fork = 0;
	curr->is_eating = 1;
	print_fork(data, curr->nb);
	gettimeofday(&data->current_time, NULL);
	if (data->t_eat > curr->t_to_die)
		curr->dead = 1;
	else
	{
		data->how_many_time_ate++;
		print_eat(data, curr->nb);
		usleep(data->t_eat * 1000);
	gettimeofday(&data->current_time, NULL);
	}
	curr->fork = 1;
	if (curr->next != NULL)
		curr->next->fork = 1;
	curr->is_eating = 0;
	print_sleep(data, curr->nb);
	curr->is_sleeping = 1;
	usleep(data->t_sleep * 1000);
	curr->is_sleeping = 0;
	gettimeofday(&data->current_time, NULL);
	pthread_mutex_unlock(&curr->mutex);
	return NULL;
}

void	print_eat(t_data *data, int nb)
{
//	ft_putnbr(nb);
//	ft_putstr(" is eating\n");
//	printf("%ld %d is eating\n", data->current_time.tv_sec * 1000 + data->current_time.tv_usec / 1000, nb);
	printf("%ld %d is eating\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000),  nb);
}

void	print_fork(t_data *data, int nb)
{
//	ft_putnbr(nb);
//	ft_putstr(" has taken a fork\n");
	printf("%ld %d has taken a fork\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000),  nb);
}

void	print_sleep(t_data *data, int nb)
{
//	ft_putnbr(nb);
//	ft_putstr(" is sleeping\n");
	printf("%ld %d is sleeping\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000),  nb);
}

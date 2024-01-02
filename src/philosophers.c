/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:14:21 by naherbal          #+#    #+#             */
/*   Updated: 2023/12/26 19:57:36 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"
/*
void	philosophers(t_data *data)
{
	t_philo *curr;

	curr = data->philos;
	give_forks(data);
//	gettimeofday(&data->start_time, NULL);
	while (curr != NULL)
	{
		gettimeofday(&data->current_time, NULL);
		printf("start_time == %ld	current_time == %ld	other_time == %ld	u_sec == %d\n", data->start_time.tv_sec, data->current_time.tv_sec, data->current_time.tv_sec - data->start_time.tv_sec, (data->current_time.tv_usec - data->start_time.tv_usec) / 1000);
		data->how_many_time_ate++;
		usleep(1000000);
		curr = curr->next;
	}
}
*/

void	philosophers(t_data *data)
{
	t_philo	*curr;

	curr = data->philos;
	while (curr != NULL)
	{
		if (can_eat(curr) == 0)
		{
			data->curr = curr;
			pthread_create(&curr->thread, NULL, make_philo_eat, data);
			pthread_join(curr->thread, NULL);
		}
		else
			philo_thinks(data, curr);
		curr = curr->next;
	}
}

int	can_eat(t_philo *curr)
{
	if (curr->is_eating == 0 && curr->is_thinking == 0 && curr->is_sleeping == 0
			&& curr->fork == 1)
		return (0);
	return (1);
}

void	philo_thinks(t_data *data, t_philo *curr)
{
	printf("%ld %d is thinking\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000), curr->nb);
	curr->is_thinking = 1;
	usleep(data->t_eat * 1000); // need to find out how much time is needed to the next philosophers to finish eating so this one thinks until a fork is free
	curr->is_thinking = 0;
}

void	give_forks(t_data *data)
{
	t_philo	*curr;

	curr = data->philos;
	while (curr != NULL)
	{
		gettimeofday(&data->current_time, NULL);
		if (curr->next && curr->next->fork == 1)
		{
			curr->fork = 2;
			//curr->next->fork = 0;
			printf("%ldms %d has taken a fork\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000), curr->nb);
			//printf("%ldms %d has taken a fork\n", data->current_time.tv_sec - data->start_time.tv_sec, curr->nb);
			printf("%ldms %d has taken a fork\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000), curr->nb);
		}
		if (curr->fork == 2)
		{
			printf("%ldms %d is eating\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000), curr->nb);
			data->how_many_time_ate++;
			usleep(data->t_eat * 1000);
		}
		curr = curr->next;
	}
}

void	around_the_table(t_data *data)
{
	gettimeofday(&data->start_time, NULL);
	while (is_dead_or_done_eating(data) == 0)
	{
		gettimeofday(&data->current_time, NULL);
		philosophers(data);
		if (data->nb_philo * data->how_many_time_eat <= data->how_many_time_ate)
			return ;
//		printf("tv_sec == %ld	tv_usec == %d\n", (data->current_time.tv_sec - data->start_time.tv_sec) * 1000 + (data->current_time.tv_usec / 1000), data->current_time.tv_usec - data->start_time.tv_usec);
	}
}

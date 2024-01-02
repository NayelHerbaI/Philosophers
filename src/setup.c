/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:20:19 by naherbal          #+#    #+#             */
/*   Updated: 2023/11/29 15:19:33 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	setup(t_data *data, char **av)
{
	setup_args(data, av);
	create_first_philosopher(data);
}

void	setup_args(t_data *data, char **av)
{
	data->nb_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (av[5])
		data->how_many_time_eat = ft_atoi(av[5]);
	data->how_many_time_ate = 0;
}

void	create_first_philosopher(t_data *data)
{
	int	i;

	i = 2;
	data->philos = malloc(sizeof(t_philo));
	data->philos->nb = 1;
	data->philos->next = NULL;
	data->philos->is_eating = 0;
	data->philos->is_thinking = 0;
	data->philos->is_sleeping = 0;
	data->philos->dead = 0;
	data->philos->fork = 1;
	data->philos->t_to_die = data->t_die;
	pthread_mutex_init(&data->philos->mutex, NULL);
	while (i <= data->nb_philo)
		create_remaining_philosophers(data, i++);
}

void	create_remaining_philosophers(t_data *data, int i)
{
	t_philo	*head;

	head = data->philos;
	while (head->next != NULL)
		head = head->next;
	head->next = malloc(sizeof(t_philo));
	head->next->nb = i;
	head->next->is_eating = 0;
	head->next->is_thinking = 0;
	head->next->is_sleeping = 0;
	head->next->fork = 1;
	head->next->dead = 0;
	head->next->t_to_die = data->t_die;
	pthread_mutex_init(&head->next->mutex, NULL);
	head->next->next = NULL;
}

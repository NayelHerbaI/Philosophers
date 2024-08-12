/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherbal <nherbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:13:15 by naherbal          #+#    #+#             */
/*   Updated: 2024/08/11 19:30:35 by nherbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

t_data	*setup_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->n_philo = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->dead = 0;
	data->finished = 0;
	data->s_time = get_time();
	if (ac == 6)
		data->n_meals = ft_atoi(av[5]);
	else
		data->n_meals = -1;
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->lock, NULL);
	setup_philo(data);
	setup_forks(data);
	return (data);
}

void	setup_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		data->philos[i].nb = i + 1;
		data->philos[i].data = data;
		data->philos[i].count = 0;
		i++;
	}
}

void	setup_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo) // initialize all forks mutexes
		pthread_mutex_init(&data->philos[i++].fork, NULL);
	i = 0;
	while (i < data->n_philo) // set up right philosopher and left philosopher forks for every philo
	{
		if (i == 0) // first philo
			data->philos[i].r_fork = &data->philos[data->n_philo - 1]; // the last philosopher is on the first one's right
		else // set up right philo fork
			data->philos[i].r_fork = &data->philos[i - 1]; // right side
		if (i + 1 == data->n_philo) // the first philosopher is on the last's left
			data->philos[i].l_fork = &data->philos[0];
		else
			data->philos[i].l_fork = &data->philos[i + 1]; // left side
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherbal <nherbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:04:02 by naherbal          #+#    #+#             */
/*   Updated: 2024/08/11 21:30:43 by nherbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	single_phil(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&philo->fork);
	message(philo, "has taken a fork");
	my_sleep(data, data->t_death);
	message(philo, "died");
	pthread_mutex_unlock(&philo->fork);
	data->dead = 1;
}

void	*philo(void *phil)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)phil;
	data = philo->data;
	if (philo->data->n_philo == 1)
	{
		single_phil(data, philo);
		return (NULL);
	}
	if (philo->nb % 2 == 0)
		usleep(1000);
	while (data->finished != 1 && data->dead != 1)
	{
		eat(philo);
		message(philo, "is sleeping");
		my_sleep(data, data->t_sleep);
		message(philo, "is thinking");
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&philo->fork); // premier prend une fourchette
	message(philo, "has taken a fork");
	pthread_mutex_lock(&philo->l_fork->fork); // reprend une fourchette a sa gauche
	message(philo, "has taken a fork");
	pthread_mutex_lock(&data->lock); // lock pour le count
	philo->count++;
	message(philo, "is eating"); 
	philo->last_meal = get_time(); // derniere fois qu'il a manger pour savoir s'il meurt
	pthread_mutex_unlock(&data->lock);
	my_sleep(data, data->t_eat);
	pthread_mutex_unlock(&philo->fork);
	pthread_mutex_unlock(&philo->l_fork->fork);
} 

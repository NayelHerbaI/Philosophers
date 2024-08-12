/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:25:02 by naherbal          #+#    #+#             */
/*   Updated: 2024/03/05 16:53:19 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	free_exit(t_data *data, pthread_t *th)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
		pthread_join(th[i++], NULL);
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->philos[i++].fork);
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	free(data->philos);
	free(data);
	free(th);
}

int	main(int ac, char **av)
{
	t_data		*data;
	pthread_t	*th;
	int			i;

	i = 0;
	if (check_error(ac, av) != 0)
		return (1);
	data = setup_data(ac, av);
	th = malloc(sizeof(pthread_t) * data->n_philo);
	while (i < data->n_philo)
	{
		if (pthread_create(&th[i], NULL, &philo, &data->philos[i]))
		{
			free(th);
			free(data->philos);
			return (printf("Thread creation failed\n"));
		}
		pthread_mutex_lock(&data->lock);
		data->philos[i].last_meal = data->s_time;
		pthread_mutex_unlock(&data->lock);
		i++;
	}
	death(data);
	free_exit(data, th);
	return (0);
}

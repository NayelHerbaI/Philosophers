/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:16:19 by naherbal          #+#    #+#             */
/*   Updated: 2023/11/29 11:05:37 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	display_philos_info(t_data *data);

int	main(int ac, char **av)
{
	t_data *data;

	if (error_handling(ac, av) != 0)
		return (1);
	data = malloc(sizeof(t_data));
	setup(data, av);
	around_the_table(data);
//	display_philos_info(data);
	return (0);
}

void	display_philos_info(t_data *data)
{
	t_philo	*head;

	head = data->philos;
	while (head != NULL)
	{
		printf("philo nb %d avec %d	%d	%d			t_die == %d\n", head->nb, head->is_eating, head->is_thinking, head->is_sleeping, head->t_to_die);
		head = head->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nherbal <nherbal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:26:28 by naherbal          #+#    #+#             */
/*   Updated: 2024/08/11 19:22:58 by nherbal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				count;
	int				nb;
	size_t			last_meal;
	struct s_data	*data;
	struct s_philo	*l_fork;
	struct s_philo	*r_fork;
	pthread_mutex_t	fork;
}					t_philo;

typedef struct s_data
{
	int				t_death;
	int				t_eat;
	int				t_sleep;
	int				n_philo;
	int				n_meals;
	size_t			s_time;
	int				finished;
	int				dead;
	t_philo			*philos;
	pthread_mutex_t	write;
	pthread_mutex_t	lock;
}					t_data;

int		check_error(int ac, char **av);
int		check_numbers(int ac, char **av);
int		ft_atoi(char *str);
size_t	get_time(void);
t_data	*setup_data(int ac, char **av);
void	setup_philo(t_data *data);
void	setup_forks(t_data *data);
void	*philo(void *phil);
void	my_sleep(t_data *data, int t_death);
void	message(t_philo *philo, char *msg);
void	eat(t_philo *philo);
void	death(t_data *data);
void	is_dead(t_data *data, int i);
void	single_phil(t_data *data, t_philo *philo);

#endif

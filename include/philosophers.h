/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:04:12 by naherbal          #+#    #+#             */
/*   Updated: 2023/11/29 15:14:17 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				nb;
	int				is_eating;
	int				is_thinking;
	int				is_sleeping;
	int				dead;
	int				fork;
	int				t_to_die;
	struct s_philo	*next;
	pthread_t		thread;
	pthread_mutex_t	mutex;
}			t_philo;

typedef struct s_data
{
	t_philo 		*philos;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	struct timeval	start_time;
	struct timeval	current_time;
	int				how_many_time_ate;
	int				how_many_time_eat;
	t_philo			*curr;
}			t_data;

void	ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int n);
int		error_handling(int ac, char **av);
int		is_num(char **av);
int		ft_atoi(char *str);
void	setup(t_data *data, char **av);
void	setup_args(t_data *data, char **av);
void	create_first_philosopher(t_data *data);
void	create_remaining_philosophers(t_data *data, int i);
void	around_the_table(t_data *data);
int		is_dead_or_done_eating(t_data *data);
void	philosophers(t_data *data);
int		can_eat(t_philo *curr);
void	philo_thinks(t_data *data, t_philo *curr);
void	*make_philo_eat(void *void_data);
void	print_eat(t_data *data, int nb);
void	print_fork(t_data *data, int nb);
void	print_sleep(t_data *data, int nb);
void	give_forks(t_data *data);

#endif

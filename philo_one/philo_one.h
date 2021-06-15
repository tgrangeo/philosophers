/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:42 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/15 14:25:39 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <limits.h>
# include <stdlib.h>
# include <sys/time.h>

# define TYPE_DIE 0
# define TYPE_EAT 1
# define TYPE_SLEEP 2
# define TYPE_THINK 3
# define TYPE_FORK 4

typedef struct s_mor
{
	int				*fork;
	int				size_fork;
	int				repas;
	struct timeval	begin;
	struct timeval	now;
	pthread_mutex_t	*death;
	pthread_mutex_t	*mutex_parole;
	pthread_mutex_t	*m_fork;
}				t_mor;

typedef struct s_struct
{
	int				id;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				fork;
	int				*next_fork;
	struct timeval	last_eat;
	t_mor			*more;
}				t_struct;

long	ft_atoi(const char *str);
int		error(char *str, t_struct *p);
int		ft_strlen(char *str);
int		ft_create_thread(t_struct *philo);
int		ft_eat(t_struct *p);
void	ft_message(int type, t_struct *p);
long	ft_conv_to_ms(struct timeval philo_time, struct timeval start_time);
int		ft_die(t_struct *p);
int		check_arg(int ac, char **av);
int		my_sleep(t_struct *p, int time);
int		ft_free(t_struct *p);
int		ft_eat(t_struct *p);
int		wait_fork(t_struct *p);
void	*only_one_philo(int t_die);
int		ft_check_arg2(char **av);
int		ft_check_arg2(char **av);

#endif
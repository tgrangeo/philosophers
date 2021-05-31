/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:42 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/21 22:20:54 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/time.h>

# define TYPE_DIE 0
# define TYPE_EAT 1
# define TYPE_SLEEP 2
# define TYPE_THINK 3
# define TYPE_FORK 4
# define TYPE_FORK_2 5
# define TYPE_END_EAT 6

typedef	struct s_mor
{
	int *fork;
	int size_fork;
	pthread_mutex_t *mutex_parole;
	struct timeval begin;
	struct timeval now;
}				t_mor;

typedef struct s_struct
{
	int	id;
	int nb_philo;
	int t_die;
	int t_eat;
    int t_sleep;
    int nb_eat;
	int fork;
	int *next_fork;
	struct timeval last_eat;
	pthread_mutex_t *m_fork;
	pthread_mutex_t *m_next_fork;
	t_mor	*more;
}				t_struct;

long	ft_atoi(const char *str);
void   	error(int ret, char *str);
int		ft_strlen(char *str);
int     ft_create_thread(t_struct *philo);
int		ft_init_2(t_struct *p);
void	ft_eat(t_struct *p);
void    ft_message(int type, t_struct *p);
void    ft_sleep(t_struct *p);
long    ft_conv_to_ms(struct timeval philo_time, struct timeval start_time);
void	ft_die(t_struct *p);

#endif
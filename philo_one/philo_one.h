/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:42 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/14 13:53:07 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <limits.h>
#include <stdlib.h>

typedef	struct s_mor
{
	int *fork;
	int size_fork;
	pthread_mutex_t *mutex_fork;
}				t_mor;

typedef struct s_struct
{
	int	id;
	int nb_philo;
	int t_die;
	int t_eat;
    int t_sleep;
    int nb_eat;
	t_mor	*more;
}				t_struct;

long	ft_atoi(const char *str);
void   	error(int ret, char *str);
int		ft_strlen(char *str);
int     ft_create_thread(t_struct *philo);
int ft_init_2(t_struct *p);
void	ft_eat(t_struct *p);

#endif
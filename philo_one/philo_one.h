/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:42 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/30 13:59:49 by tgrangeo         ###   ########lyon.fr   */
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
	int fork;
}				t_mor;

typedef struct s_arg
{
	int	id;
	int nb_philo;
	int t_die;
	int t_eat;
    int t_sleep;
    int nb_eat;
	t_mor	*more;
}				t_arg;

long	ft_atoi(const char *str);
void   	error(int ret, char *str);
int		ft_strlen(char *str);

#endif
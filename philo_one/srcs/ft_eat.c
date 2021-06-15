/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/15 13:40:54 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int	wait_fork(t_struct *p)
{
	while (1)
	{
		if (ft_die(p))
			return (0);
		pthread_mutex_lock(p->more->m_fork);
		usleep(5);
		if (p->fork == 0 && *p->next_fork == 0)
		{
			p->fork = 1;
			*p->next_fork = 1;
			ft_message(TYPE_FORK, p);
			ft_message(TYPE_FORK, p);
			pthread_mutex_unlock(p->more->m_fork);
			return (1);
		}
		pthread_mutex_unlock(p->more->m_fork);
	}
	return (1);
}

int	ft_eat(t_struct *p)
{
	ft_message(TYPE_EAT, p);
	gettimeofday(&p->last_eat, NULL);
	my_sleep(p, p->t_eat);
	if (p->nb_eat > -1)
	{
		p->more->repas++;
		if (p->more->repas == p->nb_eat * p->nb_philo)
		{
			pthread_mutex_unlock(p->more->death);
			pthread_mutex_lock(p->more->mutex_parole);
			return (1);
		}
	}
	p->fork = 0;
	*p->next_fork = 0;
	return (0);
}

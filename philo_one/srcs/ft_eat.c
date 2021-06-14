/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/14 14:10:15 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int	wait_fork(t_struct *p)
{
	if (p->nb_philo == 1)
		return (1);

	while (1)
	{
		if (ft_die(p))
			return (0);
		pthread_mutex_lock(p->more->m_fork);
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

static int	ft_eat_2(t_struct *p)
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
			return (1);	
		}
	}
   p->fork = 0;
   *p->next_fork = 0;
	return (0);
}

int    ft_eat(t_struct *p)
{
	gettimeofday(&p->last_eat, NULL);
	while (1)
	{
		usleep(10);
		if (wait_fork(p))
		{
			if (p->nb_philo == 1)
				if (ft_die(p))
					break ;
			if (ft_eat_2(p))
				break ;
   		}
		ft_message(TYPE_SLEEP, p);
		my_sleep(p, p->t_sleep);
		if (ft_die(p))
			break;
		ft_message(TYPE_THINK, p);
	}
	return (0);
}
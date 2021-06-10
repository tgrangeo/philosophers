/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/10 11:52:18 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int	wait_fork(t_struct *p)
{
	if (p->nb_philo == 1)
		return (1);
	while (!(p->fork == 0) && !(*p->next_fork == 0))
	{
		usleep(10);
		if (p->last_eat.tv_usec > 0)
			ft_die(p);
	}
	return (1);
	
}

void    ft_eat(t_struct *p)
{
	usleep(10);
	while (1)
	{
		if (wait_fork(p))
		{
			if (p->nb_philo == 1)
				ft_die(p);
			//PREND ET VERROUILLE CES FOURCHETTES
    		pthread_mutex_lock(p->m_fork);
    		p->fork = 1;
			pthread_mutex_lock(p->m_next_fork);
        	*p->next_fork = 1;
    		ft_message(TYPE_FORK, p);
        	ft_message(TYPE_FORK, p);
			//MANGE
    		ft_message(TYPE_EAT, p);
			gettimeofday(&p->last_eat, NULL);
			my_sleep(p, p->t_eat);

			if (p->nb_eat > -1)
			{
					p->more->repas++;
				if (p->more->repas == p->nb_eat * p->nb_philo)
					error(0, "");	
			}
				
			//REND CES FOURCHETTES
    		p->fork = 0;
    		pthread_mutex_unlock(p->m_fork);
    		*p->next_fork = 0;
    		pthread_mutex_unlock(p->m_next_fork);
   		}
		ft_message(TYPE_SLEEP, p);
		my_sleep(p, p->t_sleep);
		//usleep(p->t_sleep * 1000);
		ft_die(p);
		ft_message(TYPE_THINK, p);
	}
}

void    ft_sleep(t_struct *p)
{
    ft_message(TYPE_SLEEP, p);
    usleep(p->t_sleep * 100);
	//ft_die(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/07 22:49:40 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int	wait_fork(t_struct *p)
{
	while (!(p->fork == 0) || !(*p->next_fork == 0))
	{
		usleep(10);
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
    		usleep(p->t_eat * 1000);
	
	
			//REND CES FOURCHETTES
    		p->fork = 0;
    		pthread_mutex_unlock(p->m_fork);
    		*p->next_fork = 0;
    		pthread_mutex_unlock(p->m_next_fork);
   		}
	}
}

void    ft_sleep(t_struct *p)
{
    ft_message(TYPE_SLEEP, p);
    usleep(p->t_sleep * 100);
	ft_die(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:28:16 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/15 13:51:23 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	*ft_routine(void *p_data)
{
	t_struct	*p;

	p = p_data;
	gettimeofday(&p->last_eat, NULL);
	while (1)
	{
		if (wait_fork(p))
		{
			if (p->nb_philo == 1)
				if (ft_die(p))
					break ;
			if (ft_eat(p))
				break ;
		}
		ft_message(TYPE_SLEEP, p);
		my_sleep(p, p->t_sleep);
		ft_message(TYPE_THINK, p);
	}
	return (0);
}

int	ft_create_thread(t_struct *p)
{
	int			i;
	pthread_t	pid;

	i = 0;
	while (i < p->nb_philo)
	{
		pthread_create(&pid, NULL, ft_routine, (void *)&p[i]);
		i++;
	}
	pthread_detach(pid);
	return (1);
}

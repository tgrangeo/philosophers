/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:28:16 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/21 22:20:18 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    *ft_routine(void *p_data)
{
    t_struct *p = p_data;

    ft_eat(p);
    ft_sleep(p);
	ft_message(TYPE_THINK, p);
	ft_die(p);
    return 0;
}

int     ft_create_thread(t_struct *p)
{
    int i;
    pthread_t pid[p->nb_philo];

    i = 0;
    while (i < p->nb_philo)
    {
        pthread_create(&pid[i], NULL,ft_routine, (void *)&p[i]);
        i++;
    }
    i = 0;
    while (i < p->nb_philo)
    {
        pthread_join(pid[i], NULL);
        i++;
    }
    return 1;
}
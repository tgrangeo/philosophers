/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:28:16 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/14 13:16:47 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    *ft_routine(void *p_data)
{
    t_struct *p = p_data;

    ft_eat(p);
    return 0;
}

int     ft_create_thread(t_struct *p)
{
    int i;
    pthread_t pid;

    i = 0;
    while (i < p->nb_philo)
    {
        pthread_create(&pid, NULL,ft_routine, (void *)&p[i]);
		usleep(50);
        i++;
    }
	pthread_detach(pid);
    //i = 0;
    //while (i < p->nb_philo)
    //{
    //    pthread_join(pid[i], NULL);
	//	dprintf(1, "yo garcon\n");
    //    i++;
    //}
    return (1);
}
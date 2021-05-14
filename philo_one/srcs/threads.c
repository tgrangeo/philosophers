/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:28:16 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/14 14:26:02 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    *ft_routine(void *p_data)
{
    t_struct *p = p_data;

    //usleep(100);
    dprintf(1, "salut je suis philo %d\n", p->id);
    ft_eat(p);
    return 0;
}

int     ft_create_thread(t_struct *p)
{
    int i;
    pthread_t pid[p->nb_philo];

    i = 0;
    //dprintf(1, "%d %d %d \n", p[0].id,p[1].id,p[3].id);
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
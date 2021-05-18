/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:19:23 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/18 13:24:12 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    ft_message(int type, t_struct *p)
{
    //pthread_mutex_lock(p->more->mutex_parole);
    gettimeofday(&p->more->now, NULL);
      //dprintf(1, "%ld\n", p->more->now.tv_sec);
    printf("%ld ",ft_conv_to_ms( p->more->now,p->more->begin));
    printf("philo %d ", p->id);
    if (type == TYPE_EAT)
        printf("is eating\n");
    else if (type == TYPE_FORK)
        printf("has taken a fork\n");
    else if (type ==TYPE_SLEEP)
        printf("is sleeping\n");
    else if (type == TYPE_THINK)
        printf("is thinking\n");
    else if (type == TYPE_DIE)
        printf("is dead\n");
    //pthread_mutex_unlock(p->more->mutex_parole);
}
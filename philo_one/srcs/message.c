/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:19:23 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/21 21:48:49 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    ft_message(int type, t_struct *p)
{
    pthread_mutex_lock(p->more->mutex_parole);
    gettimeofday(&p->more->now, NULL);
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
    pthread_mutex_unlock(p->more->mutex_parole);
}
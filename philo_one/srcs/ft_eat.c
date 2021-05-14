/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/14 14:35:58 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    ft_eat(t_struct *p)
{
    //dprintf(1, "philo %d veut manger\n", p->id);
    usleep(10);
    while (1)
    {

        if ((p->more->fork[p->id] == 0 && p->more->fork[p->id + 1] == 0 && p->id != p->nb_philo) ||
            (p->id == p->nb_philo && p->more->fork[p->id] == 0 && p->more->fork[1] == 0))
        {
            pthread_mutex_lock(&p->more->mutex_fork[p->id]);
            dprintf(1, "philo %d prend la fork : %d\n",p->id,  p->id);
            p->more->fork[p->id] = 1;
            if (p->id != p->nb_philo)
            {
                pthread_mutex_lock(&p->more->mutex_fork[p->id + 1]);
                dprintf(1, "philo %d prend la fork : %d\n",p->id,  p->id + 1);
                p->more->fork[p->id + 1] = 1;
            }
            else
            {
                dprintf(1, "je dois etre philo 4 %d\n", p->id);
                pthread_mutex_lock(&p->more->mutex_fork[1]);
                dprintf(1, "philo %d prend la fork : %d\n",p->id, 1);
                p->more->fork[1] = 1;
            }

            dprintf(1, "philo %d is eating\n", p->id);

            usleep(p->t_eat);

            pthread_mutex_unlock(&p->more->mutex_fork[p->id]);
            p->more->fork[p->id] = 0;
            dprintf(1, "philo %d rend la fork : %d\n",p->id,  p->id);
            if (p->id != p->nb_philo)
            {
                pthread_mutex_unlock(&p->more->mutex_fork[p->id + 1]);
                dprintf(1, "philo %d rend la fork : %d\n",p->id,  p->id + 1);
                p->more->fork[p->id + 1] = 0;
            }
            else
            {
                pthread_mutex_unlock(&p->more->mutex_fork[1]);
                dprintf(1, "philo %d rend la fork : %d\n",p->id, 1);
                p->more->fork[1] = 0;
            }

            dprintf(1, "philo %d a finit de graille\n", p->id);
        }
    }
}

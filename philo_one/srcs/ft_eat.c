/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:40:34 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/18 13:23:21 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

//void    ft_eat(t_struct *p)
//{
    
   //e (1)
   //
   //if ((p->more->fork[p->id] == 0 && p->more->fork[p->id + 1] == 0 && p->id != p->nb_philo) ||
   //    (p->id == p->nb_philo && p->more->fork[p->id] == 0 && p->more->fork[1] == 0))
   //{
   //    pthread_mutex_lock(&p->more->mutex_fork[p->id]);
   //    p->more->fork[p->id] = 1;
   //    ft_message(TYPE_FORK, p);
   //   // dprintf(1, "fork %d = %d\n", p->id + 1,p->more->fork[p->id + 1]);
   //    if (p->id != p->nb_philo)
   //    {
   //        pthread_mutex_lock(&p->more->mutex_fork[p->id + 1]);
   //        ft_message(TYPE_FORK, p);
   //      //  dprintf(1, "fork %d = %d\n", p->id + 1,p->more->fork[p->id + 1]);
   //        p->more->fork[p->id + 1] = 1;
   //    }
   //    else
   //    {
   //        pthread_mutex_lock(&p->more->mutex_fork[1]);
   //        ft_message(TYPE_FORK, p);
   //      //  dprintf(1, "fork %d = %d\n", p->id + 1,p->more->fork[p->id + 1]);
   //        p->more->fork[1] = 1;
   //    }

   //    ft_message(TYPE_EAT, p);
   //    usleep(p->t_eat * 100);

   //    p->more->fork[p->id] = 0;
   //    if (p->id != p->nb_philo)
   //    {
   //        pthread_mutex_unlock(&p->more->mutex_fork[p->id + 1]);
   //        p->more->fork[p->id + 1] = 0;
   //    }
   //    else
   //    {
   //        pthread_mutex_unlock(&p->more->mutex_fork[1]);
   //        p->more->fork[1] = 0;
   //    }
   //    pthread_mutex_unlock(&p->more->mutex_fork[p->id]);
   //}
   //}
//}

void    ft_sleep(t_struct *p)
{
    ft_message(TYPE_SLEEP, p);
    usleep(p->t_sleep * 100);
}

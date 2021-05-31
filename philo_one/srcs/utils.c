/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:46:33 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/21 22:21:20 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void   error(int ret, char *str)
{
    write(1, str, ft_strlen(str));
    exit(ret);
}

long    ft_conv_to_ms(struct timeval philo_time, struct timeval start_time)
{
    long    sec;
    long    micro;
    long    mili;

    sec = philo_time.tv_sec - start_time.tv_sec;
    micro = philo_time.tv_usec - start_time.tv_usec;
    mili = micro * 0.001 + sec * 1000;
    return (mili);
}

void	ft_die(t_struct *p)
{
	long time;

	gettimeofday(&p->more->now, NULL);
	time =	ft_conv_to_ms(p->more->now, p->more->begin) + ft_conv_to_ms(p->last_eat, p->more->begin);
	if (time > p->t_die)
	{
		ft_message(TYPE_DIE, p);
		//TODO:free les mallocs et tout la 
		exit(0);	
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:46:33 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/18 11:36:40 by tgrangeo         ###   ########lyon.fr   */
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
    //dprintf(1, "s= %ld - %ld \n", philo_time.tv_sec, start_time.tv_sec);
    mili = micro * 0.001 + sec * 1000;
    //dprintf(1, "%ld %ld %ld\n", sec, micro, mili);
    return (mili);
}

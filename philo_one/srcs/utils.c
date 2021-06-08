/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:46:33 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/08 13:31:28 by tgrangeo         ###   ########lyon.fr   */
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
int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (ac < 5 || ac > 6)
		return (1);
	while (i < ac)
	{
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	ft_die(t_struct *p)
{
	long time;

	gettimeofday(&p->more->now, NULL);
	time = ft_conv_to_ms(p->more->now, p->last_eat);
	//dprintf(1,"					%d     %d < %ld\n",p->id,  p->t_die, time);
	if (time > p->t_die)
	{
		
		ft_message(TYPE_DIE, p);
		//TODO:free les mallocs et tout la 
		exit(1);	
	}
}
		
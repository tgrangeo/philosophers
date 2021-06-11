/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 10:46:33 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/11 15:09:14 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int   error(char *str, t_struct *p)
{
    write(1, str, ft_strlen(str));
	pthread_mutex_unlock(p->more->death);
	return (1);
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

int	my_sleep(t_struct *p, int time)
{

    struct timeval    now;
    struct timeval    start;

    gettimeofday(&start, NULL);
    while (1)
    {
        usleep(50);
        gettimeofday(&now, NULL);
        if  (ft_die(p))
			return (1);
        if (ft_conv_to_ms(now, start) >= time)
            break ;
    }
	return 0;
}

int	ft_die(t_struct *p)
{
	long time;

	gettimeofday(&p->more->now, NULL);
	while (p->nb_philo == 1)
	{
		gettimeofday(&p->more->now, NULL);
		if (ft_conv_to_ms(p->more->now, p->more->begin) > p->t_die)
		{
			ft_message(TYPE_DIE, p);
			//ft_free(p); 
			pthread_mutex_unlock(p->more->death);
			return (1);
			//exit(1);
		}
	}
	time = ft_conv_to_ms(p->more->now, p->last_eat);
	if (time > p->t_die)
	{
		ft_message(TYPE_DIE, p);
		pthread_mutex_lock(p->more->mutex_parole);
		pthread_mutex_unlock(p->more->death);
		return (1);
		//ft_free(p);
		//exit(1);
	}
	return (0);
}

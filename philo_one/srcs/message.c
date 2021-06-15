/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 10:19:23 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/15 14:25:31 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void	ft_message(int type, t_struct *p)
{
	char	*str;

	str = NULL;
	pthread_mutex_lock(p->more->mutex_parole);
	if (type == TYPE_EAT)
		str = "is eating";
	else if (type == TYPE_FORK)
		str = "has taken a fork";
	else if (type == TYPE_SLEEP)
		str = "is sleeping";
	else if (type == TYPE_THINK)
		str = "is thinking";
	else if (type == TYPE_DIE)
		str = "is dead";
	gettimeofday(&p->more->now, NULL);
	printf("%ld philo %d %s\n", ft_conv_to_ms(p->more->now,
			p->more->begin), p->id, str);
	pthread_mutex_unlock(p->more->mutex_parole);
}

int	ft_check_arg2(char **av)
{
	if (ft_atoi(av[1]) > INT_MAX || ft_atoi(av[1]) <= 0)
		return (1);
	if (ft_atoi(av[2]) > INT_MAX || ft_atoi(av[2]) < 11)
		return (1);
	if (ft_atoi(av[3]) > INT_MAX || ft_atoi(av[3]) < 11)
		return (1);
	if (ft_atoi(av[4]) > INT_MAX || ft_atoi(av[4]) < 11)
		return (1);
	if (av[5] != NULL)
		if (ft_atoi(av[5]) > INT_MAX || ft_atoi(av[5]) <= 0)
			return (1);
	return (0);
}

void	*only_one_philo(int t_die)
{
	usleep(t_die * 1000);
	printf("%d philo 1 is dead\n", t_die);
	return (NULL);
}

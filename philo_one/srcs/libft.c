/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:51:33 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/11 13:56:01 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

long	ft_atoi(const char *str)
{
	int					i;
	long				signe;
	unsigned long int	nb;
	char				*s;

	i = 0;
	signe = 1;
	nb = 0;
	s = (char *)str;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe = signe * -1;
			i++;
		}
		if (str[i] == '+' && signe > 0)
			i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb * signe);
}

int		ft_free(t_struct *p)
{
	int i;
	
	i = 0;
	(void)p;
	//if (p->more->mutex_parole != NULL)
	//	free(p->more->mutex_parole);
	//while (i < p->nb_philo)
	//{
	//	printf("id				%d\n", i);
	//	if (p[i].m_fork != NULL)
	//		free(p[i].m_fork);
	//	i++;
	//}
	//dprintf(1, "jsbfgiusbfifs    %p, %d\n", &p->m_fork, p->id);
//
	//dprintf(1, "jsbfgiusbfifs asdfasdfa   %p %p %d\n", &p,&p->more, p->id);
	//if (p->more != NULL)
	//	free(p->more);
	//if (p != NULL)
	//	free(p);
	return (0);
}

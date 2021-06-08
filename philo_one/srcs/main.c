/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:03 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/08 21:43:11 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int ft_init_2(t_struct *p)
{
    int i;

	i = 0;
    p->more->mutex_parole = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(p->more->mutex_parole, NULL);
    while (i < p->nb_philo)
    {
        p[i].m_fork= (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(p[i].m_fork, NULL);
        i++;
    }
    i = 0;
    while (i < p->nb_philo - 1)
    {
        p[i].m_next_fork = p[i + 1].m_fork;
        i++;
    }
    p[p->nb_philo - 1].m_next_fork = p[0].m_fork;
	int y = 0;
	while (y < p->nb_philo - 1)
	{
		p[y].fork = 0;
		p[y].next_fork = &p[y + 1].fork;
		y++;
	}
	p[p->nb_philo - 1].fork = 0;
	p[p->nb_philo - 1].next_fork = &p[0].fork;
	 return 1;

}

t_struct      *ft_init_arg(char **av) 
{
    int nb_philo;
    int i;
    t_struct      *philo;
    t_mor      *more;

    i = 0;
    nb_philo = ft_atoi(av[1]);
	if (nb_philo == 0)
		error(1, "not enough philo\n");
    more = malloc(sizeof(t_mor));
    philo = malloc(sizeof(t_struct) * nb_philo);   
    while (i < nb_philo)
    {
        philo[i].nb_philo = ft_atoi(av[1]);
        philo[i].t_die = ft_atoi(av[2]);
        philo[i].t_eat = ft_atoi(av[3]);
        philo[i].t_sleep = ft_atoi(av[4]);
        if (av[5] != NULL)
            philo[i].nb_eat = ft_atoi(av[5]);
        else
            philo[i].nb_eat = -1;
        philo[i].id = i + 1;
        philo[i].more = more;
        i++;
    }
    ft_init_2(philo);
	if (philo[i - 1].t_die < 11 || philo[i - 1].t_eat < 11 ||
		philo[i - 1].t_sleep < 11)
		error(1, "wrong arguments\n");
    return (philo);
}


int main(int ac, char **av)
{
    t_struct        *p;
    
    if (ac <= 1 || ac > 6 || check_arg(ac, av))
		error(1, "wrong arguments\n");
    p = ft_init_arg(av);
    gettimeofday(&p->more->begin, NULL);
    ft_create_thread(p);
}
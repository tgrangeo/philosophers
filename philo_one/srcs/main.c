/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:03 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/06/14 14:10:02 by tgrangeo         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

static int ft_init_2(t_struct *p)
{
    int i;

	i = 0;
    p->more->mutex_parole = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(p->more->mutex_parole, NULL);
    p->more->m_fork= (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(p->more->m_fork, NULL);
    //while (i < p->nb_philo)
    //{
    //    i++;
    //}
    //i = 0;
    //while (i < p->nb_philo - 1)
    //{
    //    p[i].m_next_fork = p[i + 1].m_fork;
    //    i++;
    //}
    //p[p->nb_philo - 1].m_next_fork = p[0].m_fork;
	int y = 0;
	while (y < p->nb_philo - 1)
	{
		p[y].fork = 0;
		p[y].next_fork = &p[y + 1].fork;
		y++;
	}
	p[p->nb_philo - 1].fork = 0;
	p[p->nb_philo - 1].next_fork = &p[0].fork;

	p->more->death = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(p->more->death, NULL);
	pthread_mutex_lock(p->more->death);
	return 1;

}

t_struct      *ft_init_arg(char **av) 
{
    int nb_philo;
    int i;
    t_struct      *philo;
    t_mor      *more;

    i = 0;
	philo = NULL;
	more = NULL;
	nb_philo = ft_atoi(av[1]);
	if (nb_philo == 0 || (av[5] != NULL && ft_atoi(av[5]) == 0))
	{
		write(1, "wrong arguments\n", 16);
		return(NULL);
	}
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
			if(error("wrong arguments\n", philo))
				return (NULL);
    return (philo);
}


int main(int ac, char **av)
{
    t_struct        *p;
    
	p = NULL;
    if (ac <= 1 || ac > 6 || check_arg(ac, av))
	{
		write(1, "wrong arguments\n", 16);
		return (1);
	}
    p = ft_init_arg(av);
	if (p == NULL)
		return (1);
	p->more->repas = 0;
    gettimeofday(&p->more->begin, NULL);
    ft_create_thread(p);
	
	pthread_mutex_lock(p->more->death);
	if (p != NULL)
		ft_free(p);
	return (0);
}
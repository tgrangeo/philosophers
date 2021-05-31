/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thomasgrangeon <thomasgrangeon@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:03 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/19 10:50:23 by thomasgrang      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_one.h"

void    scan_av(int ac, char **av)
{
    int i;

    i = 1;
    while(i < ac)
    {
        if (0 > ft_atoi(av[i]) || ft_atoi(av[i]) > INT_MAX)
            error(1, "Invalid number in arg\n");
        i++;
    }
}

t_struct      *ft_init_arg(int ac, char **av) 
{
    int nb_philo;
    int i;

    i = 0;
    scan_av(ac, av);
    nb_philo = ft_atoi(av[1]);
   
    t_struct      *philo;
    t_mor      *more;

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
    return (philo);
}

int ft_init_2(t_struct *p)
{
    ////init tableau de mutex
    //p->more->mutex_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * p->nb_philo + 1);
    //pthread_mutex_init(p->more->mutex_fork, NULL);

	
    ////init mutex parole
    p->more->mutex_parole = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(p->more->mutex_parole, NULL);

    int i = 0;

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

    //init booleene fork
	int y = 0;
	while (y < p->nb_philo - 1)
	{
		p[y].fork = 0;
		p[y].next_fork = &p[y + 1].fork;
		//dprintf(1, "%d fork %d		 next fork %d\n", y , p[y].fork, *p[y].next_fork);
		y++;
	}
	p[p->nb_philo - 1].fork = 0;
	p[p->nb_philo - 1].next_fork = &p[0].fork;
	//dprintf(1, "%d fork %d		 next fork %d\n", y , p[3].fork, *p[3].next_fork);
	
    // p->more->fork = (int *)malloc(sizeof(int) * p->nb_philo);
    // p->more->size_fork = p->nb_philo;
    // for(int i = 0; i < p->more->size_fork; i++)
    //     p->more->fork[i] = 0;
	 return 1;

}

int main(int ac, char **av)
{
    t_struct        *p;
    
    if (ac <= 1 || ac > 6)
        error(1, "Bad arguments a\n");
    p = ft_init_arg(ac, av);
    gettimeofday(&p->more->begin, NULL);
    //dprintf(1, "%ld ", p->more->begin.tv_sec);
    if (ac == 5)
    {
        ft_create_thread(p);
        printf("ok \n");
        
    }
    else
    {
        ft_create_thread(p);
        printf("dac\n");
    }
}
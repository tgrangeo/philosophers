/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:03 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/05/14 14:27:42 by tgrangeo         ###   ########lyon.fr   */
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
       //printf("salut je suis le philo %d\n", philo[i].id);
       //printf("ma fork = %d\n", philo[i].more->fork);
        i++;
    }
    ft_init_2(philo);
    return (philo);
}

int ft_init_2(t_struct *p)
{
    //init tableau de mutex
    p->more->mutex_fork = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t) * p->nb_philo + 1);
    pthread_mutex_init(p->more->mutex_fork, NULL);

    //init booleene fork
    p->more->fork = (int *)malloc(sizeof(int) * p->nb_philo + 1);
    p->more->size_fork = p->nb_philo + 1;
    for(int i = 0; i < p->more->size_fork; i++)
    {
        p->more->fork[i] = 0;
        //dprintf(1, "je suis fork %d avec pour valeur %d\n", i, p->more->fork[i]);
    }
    //dprintf(1, "%d %d\n", p->more->fork[2], p->more->size_fork);
    return 1;

}

int main(int ac, char **av)
{
    t_struct        *p;
    if (ac <= 1 || ac > 6)
        error(1, "Bad arguments a\n");
    p = ft_init_arg(ac, av);
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
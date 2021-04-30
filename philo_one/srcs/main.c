/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrangeo <tgrangeo@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:23:03 by tgrangeo          #+#    #+#             */
/*   Updated: 2021/04/30 14:29:31 by tgrangeo         ###   ########lyon.fr   */
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

void    ft_init_arg(int ac, char **av) 
{
    int nb_philo;
    int i;

    i = 0;
    scan_av(ac, av);
    nb_philo = ft_atoi(av[1]);
   
    t_arg      *philo;
    t_mor      *more;

    more = malloc(sizeof(t_mor));
    more->fork = 69;
    philo = malloc(sizeof(t_arg) * nb_philo);
   
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
        printf("salut je suis le philo %d\n", philo[i].id);
        printf("ma fork = %d\n", philo[i].more->fork);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac <= 1 || ac > 6)
        error(1, "Bad arguments ac\n");
    ft_init_arg(ac, av);
    if (ac == 5)
        printf("ok \n");
    else
        printf("dac\n");
}
/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:43:28 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 16:16:15 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_phile_eat(t_philo **stack)
{
	t_philo	*lst;

	lst = *stack;
	while (lst)
	{
		if (lst->nbr_eat != 0)
			return (0);
		lst = lst->next;
	}
	return (1);
}

void	*waiter(void *var)
{
	t_info	*cont;
	t_philo	*lst;

	cont = var;
	while (1)
	{
		if (all_phile_eat(cont->stack) == 1)
			return (NULL);
		lst = *cont->stack;
		while (lst)
		{
			if ((get_time_of_day() - lst->last_eat) >= lst->cont->time_die)
			{
				printf("%s", KGREEN);
				print_msg(" is died", lst);
				pthread_mutex_lock(&lst->cont->mutex_print);
				return (NULL);
			}
			lst = lst->next;
		}
	}
	return (NULL);
}

int	simulation_start(t_info *cont)
{
	pthread_t	trd;
	t_philo		*lst;

	lst = *cont->stack;
	while (lst)
	{
		lst->cont = cont;
		lst->n_time = get_time_of_day();
		lst->last_eat = get_time_of_day();
		if (pthread_create(&lst->philo, NULL, philosophers, lst))
			return ((ft_exit(3)), (0));
		lst = lst->next;
	}
	if (pthread_create(&trd, NULL, waiter, cont))
		return ((ft_exit(3)), (0));
	if (pthread_join(trd, NULL))
		return ((ft_exit(3)), (0));
	return (0);
}

int	main(int ac, char **argv)
{
	pthread_mutex_t	mutex_p;
	t_info			*cont;

	if (ac != 5 && ac != 6)
		return (ft_exit(1));
	cont = (t_info *)malloc(sizeof(t_info));
	if (!cont)
		return (ft_exit(0));
	cont = check_argv_and_return_content(argv, cont);
	if (!cont)
		return (0);
	cont = init_mutex_and_philo(cont);
	if (!cont)
		return (0);
	if (pthread_mutex_init(&mutex_p, NULL))
		return (ft_exit(2), 0);
	cont->mutex_print = mutex_p;
	simulation_start(cont);
	ft_free(cont);
	return (0);
}

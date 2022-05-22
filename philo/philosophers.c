/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:33:37 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 16:36:51 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	check_nbr_eat(t_philo *lst)
{
	if (lst->nbr_eat > 0)
		lst->nbr_eat--;
}

void	*philosophers(void *ptr)
{
	t_philo	*lst;

	lst = ptr;
	if (lst->numbre % 2)
		ft_usleep(40);
	print_msg("is thinking", lst);
	while (1)
	{
		pthread_mutex_lock(&lst->cont->frk[lst->numbre]);
		print_msg("has taken a fork", lst);
		pthread_mutex_lock(&lst->cont->frk[lst->numbre_next]);
		print_msg("has taken a fork", lst);
		lst->last_eat = get_time_of_day();
		print_msg("is eating", lst);
		ft_usleep(lst->cont->time_eat);
		pthread_mutex_unlock(&lst->cont->frk[lst->numbre]);
		pthread_mutex_unlock(&lst->cont->frk[lst->numbre_next]);
		check_nbr_eat(lst);
		if (lst->nbr_eat == 0)
			break ;
		print_msg("is sleeping", lst);
		ft_usleep(lst->cont->time_sleep);
		print_msg("is thinking", lst);
	}
	return (NULL);
}

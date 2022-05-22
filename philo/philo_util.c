/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:34:39 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 22:03:40 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(int index)
{
	if (index == 0)
		printf("%serror...	: malloc ...\n", KRED);
	else if (index == 1)
		printf("%serror...	: arguments\n", KRED);
	else if (index == 2)
		printf("%serror...	: mutex ...\n", KRED);
	else if (index == 3)
		printf("%serror...	: thread create\n", KRED);
	return (0);
}

long	get_time_of_day(void)
{
	struct timeval	time;
	long			milliseconds;

	gettimeofday(&time, NULL);
	milliseconds = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (milliseconds);
}

void	print_msg(char *msg, t_philo *lst)
{
	pthread_mutex_lock(&lst->cont->mutex_print);
	printf("%ld ms : %d  %s\n", get_time_of_day() - lst->n_time,
		lst->numbre + 1, msg);
	pthread_mutex_unlock(&lst->cont->mutex_print);
}

void	ft_usleep(long ms)
{
	long	end;

	end = get_time_of_day() + ms;
	while (get_time_of_day() < end)
		usleep(50);
}

void	ft_free(t_info *cont)
{
	t_philo	*lst;
	int		i;

	i = 0;
	while (++i < cont->num_philo)
		pthread_mutex_destroy(&cont->frk[i]);
	pthread_mutex_destroy(&cont->mutex_print);
	lst = *cont->stack;
	while (lst)
	{
		free(lst);
		lst = lst->next;
	}
	free(cont->stack);
	free(cont->frk);
	free(cont);
}

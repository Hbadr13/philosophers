/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:30:51 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 22:03:15 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_info	*check_argv_and_return_content(char **argv, t_info *cont)
{
	cont->time_die = ft_atoi(argv[2]);
	cont->time_eat = ft_atoi(argv[3]);
	cont->time_sleep = ft_atoi(argv[4]);
	cont->number_eat = -1;
	if (cont->num_philo == -1 || cont->time_die == -1
		|| cont->time_eat == -1 || cont->time_sleep == -1)
		return (ft_exit(1), (NULL));
	if (argv[5])
	{
		cont->number_eat = ft_atoi(argv[5]);
		if (cont->number_eat == -1)
			return (ft_exit(1), (NULL));
	}
	cont->num_philo = ft_atoi(argv[1]);
	if (cont->num_philo == -1)
		return (ft_exit(1), (NULL));
	return (cont);
}

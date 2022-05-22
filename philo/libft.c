/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 12:32:51 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 15:39:07 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

static	int	ft_atoi_help(char *str, int *i, int *nb)
{
	while (str[*i])
	{
		if (str[*i] < '0' || str[*i] > '9')
			return (-1);
		*nb = *nb * 10 + str[*i] - '0';
		(*i)++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		sing;
	int		i;
	int		nb;

	nb = 0;
	sing = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sing = sing * -1;
		i++;
	}
	if (!str[i])
		return (-1);
	if ((ft_atoi_help(str, &i, &nb) == -1))
		return (-1);
	if ((nb * sing) < 1 || (nb * sing) > 2147483647)
		return (-1);
	return (nb * sing);
}

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*new_fin;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new_fin = *alst;
	while (new_fin)
	{
		if (!new_fin->next)
			break ;
		new_fin = new_fin->next;
	}
	new_fin->next = new;
}

t_philo	*ft_lstnew(int nb, int nb_next)
{
	t_philo	*n_node;

	n_node = (t_philo *)malloc(sizeof(t_philo));
	if (!n_node)
		return (NULL);
	n_node->numbre = nb;
	n_node->numbre_next = nb_next;
	n_node->next = NULL;
	return (n_node);
}

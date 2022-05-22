/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 15:30:00 by hbadr             #+#    #+#             */
/*   Updated: 2022/05/21 22:30:28 by hbadr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define KRED  	"\x1B[31m"
# define KYELLOW "\x1B[32m"
# define KGREEN   "\x1B[33m"
# define KBLUE  "\x1B[34m"
# define KMAGENTA  "\x1B[35m"
# define KCYAN  "\x1B[36m"
# define KWHITE  "\x1B[37m"
# define KNORMAL  "\x1B[0m"

typedef struct philosophers{
	int						num_philo;
	long					time_die;
	long					time_eat;
	long					time_sleep;
	int						number_eat;
	struct philosopherss	**stack;
	pthread_mutex_t			*frk;
	pthread_mutex_t			mutex_print;
}t_info;

typedef struct philosopherss{
	pthread_mutex_t			left;
	pthread_mutex_t			right;
	pthread_t				philo;
	int						nbr_eat;
	int						numbre;
	int						numbre_next;
	long					n_time;
	long					last_eat;
	struct philosophers		*cont;
	struct philosopherss	*next;
}t_philo;

int		main(int ac, char **argv);
t_info	*check_argv_and_return_content(char **argv, t_info *cont);
int		ft_atoi(char	*str);
int		ft_exit(int index);
long	get_time_of_day(void);
t_info	*init_mutex_and_philo(t_info *cont);
t_philo	*ft_lstnew(int nb, int nb_mext);
void	ft_lstadd_back(t_philo **alst, t_philo *new);
void	*philosophers(void *ptr);
void	print_msg(char *msg, t_philo *lst);
long	get_time_of_day(void);
void	ft_usleep(long ms);
int		all_phile_eat(t_philo **stack);
void	ft_free(t_info *cont);
#endif
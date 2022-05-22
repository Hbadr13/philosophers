# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hbadr <hbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:36:09 by hbadr             #+#    #+#              #
#    Updated: 2022/05/21 15:21:12 by hbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
SRC = main.c check_args.c libft.c philo_util.c  init_philo.c philosophers.c

OBJ = ${SRC:.c=.o}
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
HEADERS = philosophers.h

GREEN  = \033[1;32m
YELLOW = \033[1;33m

all : $(NAME)

%.o:%.c  $(HEADERS)
	@$(CC)  $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ)  -o $(NAME)
	@echo "$(GREEN)---> success!"
clean :
	@rm -f $(OBJ)
	@echo "${YELLOW}---> object files deleted!"

fclean : clean
	@rm -f $(NAME)
	@echo "${YELLOW}---> all deleted!"
re : fclean all

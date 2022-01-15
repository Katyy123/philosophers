# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 15:44:51 by cfiliber          #+#    #+#              #
#    Updated: 2022/01/15 19:47:44 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = main.c \
	parsing.c \
	init.c \
	threads.c \
	philos_activity.c \
	thread_utils.c \
	end.c \
	utils.c \
	errors.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address #-fsanitize=thread

RED = '\x1b[31m'
GREEN = '\x1b[32m'
YELLOW = '\x1b[33m'
BLUE = '\x1b[0;34m'
MAGENTA = '\x1b[35m'
CYAN = '\x1b[36m'
GRAY = '\x1b[2;37m'
CURSIVE = '\x1b[3m'
RESET = '\x1b[0m'

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll files have been compiled"$(RESET)
	@echo $(MAGENTA)$(CURSIVE)"\nType ./philo nb_philos time_die time_eat time_sleep times_must_eat\n"$(RESET)

clean:
	rm -f $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll object files have been removed\n"$(RESET)

fclean: clean
	rm -f $(NAME)
	@echo $(GREEN)$(CURSIVE)"\nThe executable philo has been removed\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re

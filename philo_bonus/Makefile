# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 19:30:54 by cfiliber          #+#    #+#              #
#    Updated: 2022/01/20 17:39:23 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRCS = main.c \
	parsing.c \
	init.c \
	processes.c \
	philos_activity.c \
	process_utils.c \
	end.c \
	utils.c \
	errors.c \

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

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
	@echo $(MAGENTA)$(CURSIVE)"\nType ./philo_bonus nb_philos time_die time_eat time_sleep times_must_eat\n"$(RESET)

clean:
	rm -f $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll object files have been removed\n"$(RESET)

fclean: clean
	rm -f $(NAME)
	@echo $(GREEN)$(CURSIVE)"\nThe executable philo_bonus has been removed\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 15:44:51 by cfiliber          #+#    #+#              #
#    Updated: 2021/12/11 15:56:53 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = $(MAIN_SRC) $(SRC_GNL) $(SRC_MAP) $(SRC_GAME)

MAIN_SRC = main.c errors.c

GNL = get_next_line.c get_next_line_utils.c
SRC_GNL = $(addprefix gnl/, $(GNL))

MAP = map_reader.c map_checker.c map_checker_2.c map_utils.c tile_map_gen.c
SRC_MAP = $(addprefix map/, $(MAP))

GAME = game_init.c input.c render.c end_program.c
SRC_GAME = $(addprefix game/, $(GAME))

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

GREEN = '\x1b[32m'
YELLOW = '\x1b[33m'
RED = '\x1b[31m'
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
	@echo $(MAGENTA)$(CURSIVE)"\nType instructions to run the program\n"$(RESET)

clean:
	rm -f $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll object files have been removed\n"$(RESET)

fclean: clean
	rm -f $(NAME)
	@echo $(GREEN)$(CURSIVE)"\nThe executable philo has been removed\n"$(RESET)

re: fclean all

.PHONY: all clean fclean re

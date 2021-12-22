# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 22:46:26 by mamaquig          #+#    #+#              #
#    Updated: 2021/12/21 17:42:45 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRC			=	$(addprefix src/,				\
					main.c						\
					routine.c					\
					data_struct.c				\
					memory_allocation.c			\
					utils.c						\
					list.c						\
				)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -lpthread
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADER) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

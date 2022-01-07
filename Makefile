# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 22:46:26 by mamaquig          #+#    #+#              #
#    Updated: 2022/01/07 19:24:29 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRC			=	$(addprefix src/,				\
					conditions.c				\
					destroy.c					\
					error.c						\
					init.c						\
					list.c						\
					main.c						\
					parse.c						\
					routine.c					\
					set_time.c					\
					to_do.c						\
					utils.c						\
				)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -pthread
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=thread -g3

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

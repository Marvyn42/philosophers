# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaquig <mamaquig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 22:46:26 by mamaquig          #+#    #+#              #
#    Updated: 2021/12/08 16:13:06 by mamaquig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo
SRC			=	$(addprefix src/,				\
					main.c						\
					set_args.c					\
				)								\
				$(addprefix src/utils/,			\
					ft_atoi.c					\
					ft_is_num.c					\
				)
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
HEADER		=	-Iheader -lpthread
CFLAGS		=	-D_REENTRANT 
# -Wall -Wextra -Werror
# -fsanitize=address -g3

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(HEADER) $(LIB) -o $@ $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

norme:
	norminette

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all norme clean fclean re

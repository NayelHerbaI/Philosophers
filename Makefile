# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naherbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:28:19 by naherbal          #+#    #+#              #
#    Updated: 2024/03/05 14:49:14 by naherbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	src/main.c			\
		src/check_error.c	\
		src/utils.c			\
		src/setup_data.c	\
		src/philosopher.c	\

OBJ		=	$(SRC:.c=.o)

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -g

HEADERS	=	-I include

RM		=	rm -rf

all:	$(NAME)

$(NAME):
		cc $(FLAGS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re

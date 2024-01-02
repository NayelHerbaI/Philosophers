# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naherbal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/21 20:28:19 by naherbal          #+#    #+#              #
#    Updated: 2023/12/26 19:57:41 by naherbal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	src/main.c								\
		src/error_handling.c					\
		src/setup.c								\
		src/philosophers.c						\
		src/make_philo_eat.c					\
		src/utils.c								\

OBJ		=	$(SRC:.c=.o)

NAME	=	philosopher

CFLAGS	=	-Wall -Wextra -Werror

HEADERS	=	-I includes

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			cc $(HEADERS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:	all clean fclean re

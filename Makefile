# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obalagur <obalagur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 00:45:42 by vkryvono          #+#    #+#              #
#    Updated: 2018/01/11 18:29:01 by obalagur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c\
	  ft_reader.c\
	  ft_validator.c\
	  ft_l_free.c\
	  ft_l_new.c\
	  ft_engine.c\
	  ft_comparator.c\
	  ft_addition.c\
	  ft_move.c\
	  ft_printer.c

HEADER = fillit.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) -o $(NAME)

$(OBJ):
	@gcc -c $(SRC) $(FLAGS)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

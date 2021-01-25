# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/17 14:30:59 by jinpark           #+#    #+#              #
#    Updated: 2020/01/07 18:16:11 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a
HEADER=-I libft.h
CC=gcc
CFLAG=-Wall -Wextra -Werror
SRC=$(wildcard *.c)

OBJ=$(SRC:.c=.o)

all: $(NAME)
$(NAME):$(SRC)
	@$(CC) $(CFLAGS) $(HEADER) -c $(SRC)
	@echo compiling...
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@rm -f $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f libft.a $(OBJ)

re: fclean all

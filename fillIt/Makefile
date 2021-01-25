# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 20:19:01 by jinpark           #+#    #+#              #
#    Updated: 2019/04/09 18:41:44 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = main.c solve.c extract_tetrimino.c load_tetrimino.c tetri_func.c\
	   val.c check_colrow.c array_func.c print_func.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -I libft/
LFLAGS = -g -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(SRCS)

re: fclean all

clean:
	@make -C ./libft clean

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

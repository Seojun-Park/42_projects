# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/12 18:21:45 by jinpark           #+#    #+#              #
#    Updated: 2019/04/27 14:24:40 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRCS=ft_printf.c formatting.c c_specifier.c di_specifier.c\
	 f_specifier.c f_print.c ops_func.c ops_func2.c ops_func3.c\
	 s_specifier.c u_specifier.c ox_specifier.c ops_func4.c\
	 p_specifier.c ops_func5.c ops_func6.c ops_func7.c\
	 colour_print.c

OBJS=$(SRCS:.c=.o)

CC=gcc
CFLAG=-Wall -Wextra -Werror -Og
CFLAG+=-I libft/ -I .
#LFLAG=-g -L ./libft/ -lft
LFLAG=-g

all:$(NAME)

$(NAME): $(OBJS) 
	make -C ./libft
	ar rc $(NAME) $(OBJS) libft/*.o

%.o:%.c
	$(CC) $(CFLAG) -g $< -c

re:fclean all

clean:
	@make -C ./libft clean
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C ./libft
	@rm -f $(OBJS)
	@rm -f $(NAME)

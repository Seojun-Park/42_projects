# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 22:08:42 by jinpark           #+#    #+#              #
#    Updated: 2019/06/20 20:31:39 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ssl

SRC		=	src/ft_ssl.c src/md5.c src/sha256.c src/ssl_opt.c src/ssl_opt2.c\
			src/sha224.c src/sha512.c
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
CFLAGS	+=	-I library/libft/ -I .

all		:	$(NAME)

$(NAME)	:	$(SRC)
	make -C library/libft
	$(CC) $(CFLAG) -o $(NAME) $(SRC) library/libft/*.c

%.o:%.c
	$(CC) $(CFLAG) $< -c

re: fclean all

clean:
	rm -f $(OBJ)
fclean: clean
	@make fclean -C ./library/libft
#	@rm -f $(OBJ)
	@rm -f $(NAME)

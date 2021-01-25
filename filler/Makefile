# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinpark <jinpark@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/07 21:41:36 by jinpark           #+#    #+#              #
#    Updated: 2019/08/09 22:37:03 by jinpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	jin.filler

SRC		=	src/main.c src/algo.c src/placement.c
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror -g3
CFLAG	+=	-I libft -I includes -I.

all		:	$(NAME)

$(NAME)	:	$(SRC)
	@echo "\033[32mJin's filler is being made..."
	@echo "\033[0m"
	@make -C libft
	@$(CC) $(CFLAG) -o $(NAME) $(SRC) libft/*.c

%.o:%.c
	$(CC) $(CFLAG) $< -c

re: fclean all

clean:
	@echo "\033[32mClean all"
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME).dSYM
	@rm -f $(NAME)

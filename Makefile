# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 13:28:57 by clfoltra          #+#    #+#              #
#    Updated: 2018/11/28 13:24:13 by clfoltra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c \

INC = -I libft/includes -L libft/ -lft

OBJ	= $(SRC:.c=.o)

CFLAGS	?=	-Wall -Wextra -Werror


all: $(NAME)
	
$(NAME):
	make -C libft/
	@$(CC) $(CFLAGS) $(SRC) $(INC) -o $(NAME)
	@echo compiling $@

fclean: clean
	make fclean -C libft/
	rm -f $(NAME)

clean:
	make clean -C libft/
	rm -f $(OBJ)

re: fclean all

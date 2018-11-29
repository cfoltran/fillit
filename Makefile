NAME = fillit

SRC =  utils.c \
  	  fillit.c \
	  get_next_line.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

INC = -I libft/includes -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C libft/
			$(CC) $(CFLAGS) $(INC) -o $@ $^ 

clean:
		make clean -C libft/
			rm -f $(OBJ)

fclean: clean
		make fclean -C libft/
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

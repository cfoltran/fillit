NAME = fillit

SRC = 	fillit.c \
		utils.c \
		get_next_line.c \

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

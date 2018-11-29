NAME = fillit

SRC = 	fillit.c \
		utils.c \
		get_next_line.c \

INC = -I libft/includes -L libft/ -lft

OBJ	= $(SRC:.c=.o)

CFLAGS	?=	-Wall -Wextra -Werror

all: $(NAME)
	
$(NAME):
	@make -C libft/
	@echo "\n\033[33;1mlibft \033[0;1m: [\033[1;32mOK\033[0;1m]"
	@$(CC) $(CFLAGS) $(SRC) $(INC) -o $(NAME)
	@echo "\033[33;1m$(NAME)\033[0;1m: [\033[1;32mOK\033[0;1m]"

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

clean:
	@make clean -C libft/
	@echo "\033[33;1mlibft\033[0;1m: libft deleted"
	@rm -f $(OBJ)
	@echo "\033[33;1m$(NAME)\033[0;1m: $(NAME) deleted"


re: fclean all

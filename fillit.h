#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 21
# define FILENAME "usage: ./fillit filename"
typedef struct 		s_list
{
	char			**tetri;
	char			id;
	struct s_list 	*next;
}					t_list;

#endif

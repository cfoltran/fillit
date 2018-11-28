#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 21

typedef struct 			s_coord
{
	int					x[4];
	int					y[5];
	struct s_coord		*next;
}						t_coord;

typedef struct 		s_tetri
{
	char			**tetri;
	char			id;
	t_coord			point;
	struct s_list 	*next;
}					t_tetri;

#endif

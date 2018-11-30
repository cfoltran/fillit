#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define FILENAME "usage: ./fillit filename"
# define BUFF_SIZE 21
# define TRUE 1
# define MAX_FD 4096

typedef struct 		s_coord
{
	int				x[4];
	int				y[5];
	struct s_coord	*next;
}					t_coord;

typedef struct		s_tetri
{
	char			**tetri;
	char			id;
	t_coord			point;
	struct s_tetri 	*next;
}					t_tetri;

//void				ft_tetriadd(t_tetri **tetri, t_tetri *new);
//t_tetri				*ft_tettrinew(char **tetri, char id, t_coord point);
t_tetri		        *read_piece(int fd);
t_tetri				*tetri_add(t_tetri *lst, char *line, char c);
t_tetri				*coord_add(t_tetri *lst);
int         		get_next_line(const int fd, char **line);

#endif

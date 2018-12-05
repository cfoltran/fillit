#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFF_SIZE 	21
# define MAX_FD 	4096
# define TRUE		1

# define FILEERR 	"usage: ./fillit filename"
# define ERROR 		"error"

# define END 		4
# define BLOCK 		'#'
# define EMPTY 		'.'

typedef struct		s_coord
{
	int				x[5];
	int				y[5];
	struct s_coord	*next;
}					t_coord;

typedef struct		s_tetri
{
	char			**tetri;
	char			id;
	t_coord			point;
	struct s_tetri	*next;
}					t_tetri;

void				free_lst(t_tetri *lst);
t_tetri				*coord_add(t_tetri *lst);
t_tetri				*read_file(int fd);
t_tetri				*tetri_add(t_tetri *lst, char *line, char c);
int					get_next_line(const int fd, char **line);
int					nb_piece(char **piece);
int					piece_integrity(char **piece);
int					errors(t_tetri *lst);
int					solv_fillit(t_tetri *tetri, char **tab);
int					is_tetriput(t_tetri *tetri, char **tab, int x, int y);
void				delete_tetri(t_tetri *lst, char **tab, int x, int y);
void				put_tetri(t_tetri *lst, char **tab, int x, int y);

#endif

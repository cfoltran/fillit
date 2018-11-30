#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFF_SIZE 	21
# define MAX_FD 	4096
# define TRUE		1

# define FILEERR 	"usage: ./fillit filename"
# define OPENERR 	"error : open"
# define CLOSERR 	"error : close"
# define GRIDERR 	"error : invalid grid"

# define END 		4
# define BLOCK 		'#'
# define EMPTY 		'.'

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

t_tetri				*coord_add(t_tetri *lst);
t_tetri		        *read_file(int fd);
t_tetri				*tetri_add(t_tetri *lst, char *line, char c);
int         		get_next_line(const int fd, char **line);
int				    nb_piece(char **piece);
int				    check_errors(t_tetri *lst);

#endif

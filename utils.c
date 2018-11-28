#include "fillit.h"

t_piece		read_piece(int fd)
{
	t_piece	*lst;
	char	buf[BUFF_SIZE + 1];
	int 	fd;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;	
	}
}
#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_tetri	*res;
	int 	fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		res = read_piece(fd);
		while (res)
		{
			ft_putstr(*res->tetri);
			res = res->next;
		}
		if (close(fd) == -1)
			return (-1);
	}
	else
		ft_putendl(FILENAME);
	return (0);
}

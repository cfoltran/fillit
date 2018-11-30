#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int 	fd;
	t_tetri *res;

	if (argc == 2)
	{
		int i;

		i = -1;
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_exit(OPENERR, 1);
		res = read_file(fd);
		if (!check_errors(res))
			ft_exit(GRIDERR, 1);
		while (res)
		{
			i = -1;
			while (res->tetri[++i])
				ft_putendl(res->tetri[i]);
			res = res->next;
			ft_putendl("");
		}
		if (close(fd) == -1)
			ft_exit(CLOSERR, 1);
	}
	else
		ft_exit(FILEERR, 1);
	return (0);
}

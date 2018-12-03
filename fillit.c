#include "fillit.h"
#include <stdio.h>

void	ft_putresult(char **tab)
{
	int		i;

	i = -1;
	if (tab)
		while (tab[++i])
			ft_putendl(tab[i]);
}

char	**ft_create_table(int size)
{
	int		i;
	int		j;
	char	**result;

	if (!(result = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		result[i] = ft_strnew(size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < 4)
			result[i][j] = '.';
		result[i][j] = '\0';
	}
	result[size] = NULL;
	return (result);
}


int		main(int argc, char **argv)
{
	char 	**tb;
	int 	fd;
	int		size;
	t_tetri *res;

	size = 5;
	tb = NULL;
	if (argc == 2)
	{
		int i;

		i = -1;
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_exit(OPENERR, 1);
		res = read_file(fd);
		if (!check_errors(res))
			ft_exit(GRIDERR, 1);
		if (!(tb = ft_create_table(size)))
			return (0);
		while (!solv_fillit(res, tb))
			tb = ft_create_table(size++);
		ft_putresult(tb);
			// while (res)
			// {
			// 	i = -1;
			// 	y = 0;
			// 	while (res->tetri[++i])
			// 		ft_putendl(res->tetri[i]);
			// 	while (y < 4)
			// 	{
			// 		ft_putnbr(res->point.x[y]);
			// 		ft_putnbr(res->point.y[y]);
			// 		ft_putendl("");
			// 		y++;
			// 	}
			// 	res = res->next;
			// 	ft_putendl("");
			// }
			if (close(fd) == -1)
				ft_exit(CLOSERR, 1);
	}
	else
		ft_exit(FILEERR, 1);
	return (0);
}

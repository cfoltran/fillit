#include "fillit.h"
#include <stdio.h>

void	free_table(char **tab)
{
	char	**tmp_all;
	char	*tmp;

	tmp_all = tab;
	tmp = *tab;
	while (tmp)
	{
		ft_strdel(&tmp);
		tmp = *++tab;
	}
	free(tmp_all);
}

void	free_lst(t_tetri *lst)
{
	t_tetri *tmp;

	while (lst)
	{
		tmp = lst;
		free_table(lst->tetri);
		lst = lst->next;
		free(tmp);
	}
}

void	ft_putresult(char **tab)
{
	int		i;

	i = -1;
	if (tab)
		while (tab[++i])
			ft_putendl(tab[i]);
}

char	**ft_create_table(char **tab, int size)
{
	int		i;
	int		j;
	char	**result;

	if (tab)
		free_table(tab);
	printf("sizeof(char) => %lu\n", sizeof(char));
	printf("sizeof(char*) => %lu\n", sizeof(char*));
	if (!(result = (char**)malloc(sizeof(char*) * (size))))
		return (NULL);
	i = -1;
	while (++i < size)
		result[i] = ft_strnew(size);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
			result[i][j++] = '.';
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
		if (!(tb = ft_create_table(tb, size)))
			return (0);
		while (!solv_fillit(res, tb))
			tb = ft_create_table(tb, size++);
		ft_putresult(tb);
		free_table(tb);
		free_lst(res);
		if (close(fd) == -1)
			ft_exit(CLOSERR, 1);
	}
	else
		ft_exit(FILEERR, 1);
	return (0);
}

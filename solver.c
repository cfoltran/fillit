#include "fillit.h"

void		delete_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int 	i;

	i = -1;
	while (++i < 4)
		tab[y + lst->point.y[i]][x + lst->point.x[i]] = '.';
}

void		put_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int 	i;

	i = -1;
	while (++i < 4)
		tab[y + lst->point.y[i]][x + lst->point.x[i]] = lst->id;
}

int			is_tetriput(t_tetri *lst, char **tab, int x, int y)
{
	int			i;
	int			size;

	i = -1;
	size = ft_strlen(tab[0]);
	while (++i < 4)
	{
		if (x + lst->point.x[i] >= size || y + lst->point.y[i] >= size)
		{
			printf("size => %d ", size);
			printf("number => %d ", x + lst->point.x[i]);
			printf("x => %d ", x);
			printf("lst->point.x[i] => %d \n", lst->point.x[i]);
			return (0);
		}
		if (tab[y + lst->point.y[i]][x + lst->point.x[i]] != '.')
			return (0);
	}
	return (1);
}

int			solv_fillit(t_tetri *tetri, char **tab)
{
	int 		x;
	int			y;

	y = 0;
	if (!tetri)
		return (1);
	while (tab[y])
	{
		x = 0;
		while(tab[y][x])
		{
			if (is_tetriput(tetri, tab, x, y))
			{
				put_tetri(tetri, tab, x, y);
				if (solv_fillit(tetri->next, tab))
					return (1);
				delete_tetri(tetri, tab, x, y);
			}
			++x;
		}
		++y;
	}
	return (0);
}

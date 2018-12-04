#include "fillit.h"

void		delete_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int 	i;

	i = -1;
	while (++i < 4)
		tab[x + lst->point.x[i]][y + lst->point.y[i]] = '.';
}

void		put_tetri(t_tetri *lst, char **tab, int x, int y)
{
	int 	i;

	i = -1;
	while (++i < 4)
	{
		printf("point.y: %d\n", lst->point.y[i]);
		printf("      y: %d\n", y);
		tab[x + lst->point.x[i]][y + lst->point.y[i]] = lst->id;}
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
			return (0);
		if (tab[x + lst->point.x[i]][y + lst->point.y[i]] != '.')
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
		while(tab[x][y])
		{
			if (is_tetriput(tetri, tab, x, y))
			{
				put_tetri(tetri, tab, x, y);
				if (solv_fillit(tetri->next, tab))
					return (1);
				delete_tetri(tetri, tab, x, y);
			}
			++y;
		}
		++x;
	}
	return (0);
}

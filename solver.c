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
		tab[x + lst->point.x[i]][y + lst->point.y[i]] = lst->id;
}


int			is_tetriput(t_tetri *tetri, char **tab, int x, int y)
{
	int			i;
	int 		len;

	i = -1;
	while (++i < 4)
		if (tab[x + lst->point.x[i]][y + lst->point.y[i]] != '.')
			return (0);
	return (1);
}

int			solv_fillit(t_tetri *tetri, char **tab)
{
	int 		x;
	int			y;
	t_tetri		*lst;

	while (lst)
	{
		x = 0;
		while (tab[x])
		{
			y = 0;
			while(tab[x][y])
			{
				if (is_tetriput(lst, tab, x, y))
				{
					put_tetri(lst, tab, x, y);
					if (solv_fillit(lst->next, tab))
						return (1);
					delete_tetri(lst, tab, x, y);
				}
				y++;
			}
			x++;
		}
	}
	return (0);
}

#include "fillit.h"

t_tetri			*coord_factorize(t_tetri *tetri)
{
	int			x_factor;
	int			y_factor;
	int			i;
	t_tetri		*tmp;

	tmp = tetri;
	while (tmp)
	{
		i = -1;
		x_factor = END;
		y_factor = END;
		while (++i < END)
		{
			if (tmp->point.x[i] < x_factor)
				x_factor = tmp->point.x[i];
			if (tmp->point.y[i] < y_factor)
				y_factor = tmp->point.y[i];
		}
		i = -1;
		while (++i < END)
		{
			tmp->point.x[i] -= x_factor;
			tmp->point.y[i] -= y_factor;
		}
		tmp = tmp->next;
	}
	return (tetri);
}

t_tetri			*coord_add(t_tetri *tetri)
{
	int			x;
	int			y;
	int			i;
	t_tetri		*lst;

	i = 0;
	lst = tetri;
	while (lst)
	{
		x = -1;
		i = 0;
		while ((lst->tetri)[++x])
		{
			y = -1;
			while ((lst->tetri)[x][++y] && i <= 4)
				if ((lst->tetri)[x][y] == '#')
				{
					lst->point.x[i] = x;
					lst->point.y[i] = y;
					i++;
				}
		}
		lst = lst->next;
	}
	return (coord_factorize(tetri));
}

t_tetri			*tetri_add(t_tetri *lst, char *line, char c)
{
	t_tetri		*tmp;
	t_tetri		*i;

	i = lst;
	if (!(tmp = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!lst)
		lst = tmp;
	else
	{
		while (i->next)
			i = i->next;
		i->next = tmp;
	}
	tmp->tetri = ft_strsplit(line, '\n');
	tmp->id = c;
	tmp->next = NULL;
	return (lst);
}

t_tetri			*read_file(int fd)
{
	t_tetri	*lst;
	char	*line;
	char	*tmp;
	char	id;
	int		cpt;

	cpt = 0;
	id = 'A';
	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if ((++cpt % 5) != 0 && line[4] != '\n' && line[5] != '\n')
			return (NULL);
		if (cpt == 1)
			tmp = ft_strnew(0);
		if (line[0] == '\n')
		{
			lst = tetri_add(lst, tmp, id++);
			ft_strclr(tmp);
		}
		tmp = ft_strjoinfree(tmp, line, ft_strlen(line), 0);
		ft_memdel((void *)&line);
	}
	if (!lst)
		return (NULL);
	lst = tetri_add(lst, tmp, id++);
	lst = coord_add(lst);
	ft_memdel((void *)&tmp);
	return (lst);
}

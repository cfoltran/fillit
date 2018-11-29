#include "fillit.h"
#include <stdio.h>

t_tetri		coord_add(t_tetri *lst)
{
	int 		x;
	int			y;
	int 		i;
	char 		*pos;
	t_tetri		*lst;


	lst = tetri;
	while (lst)
	{
		while ((lst->line)[x])
		{
			y = 0;
			while ((lst->line)[x][y])
			{
				if ((lst->line)[x][y] == '#')
					//do something
				lst->point.x[i] = x;
				lst->point.y[i] = y;
				y++;
			}
			x++;
		}
		lst = lst->next;
	}
	return (lst);
}

t_tetri			*tetri_add(t_tetri *lst, char *line, char c, t_coord *point)
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

t_tetri		*read_piece(int fd)
{
	t_tetri	*lst;
	t_coord *coord;
	char	*line;
	char	*tmp;
	char	id;
	int		cpt;
	int		i;

	i = 0;
	cpt = 0;
	id = 'A';
	lst = NULL;
	if (!(coord = malloc(sizeof(t_coord))))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if ((++cpt % 5) != 0 && line[4] != '\n' && line[5] != '\n')
			return (NULL);
		tmp = ft_strnew(ft_strlen(line));
		tmp = ft_strcpy(tmp, line);
		coord_add(&coord, line, cpt, &i);
		if (cpt % 5 == 0)
		{
			lst = tetri_add(lst, tmp, id++, coord);
			i = 0;
			ft_memdel((void *)&tmp);
			ft_memdel((void *)&line);
		}
	}
	return (lst);
}


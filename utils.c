#include "fillit.h"
#include <stdio.h>

t_tetri		*coord_add(t_tetri *tetri)
{
	int 		x;
	int			y;
	int 		i;
	t_tetri		*lst;


	x = 0;
	y = 0;
	i = 0;
	lst = tetri;
	while (lst)
	{
		while ((lst->tetri)[x])
		{
			y = 0;
			while ((lst->tetri)[x][y])
			{
				if ((lst->tetri)[x][y] == '#')
				{
					lst->point.x[i] = x;
					lst->point.y[i] = y;
				}
				y++;
			}
			x++;
		}
		lst = lst->next;
	}
	return (lst);
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

// void		coord_add(t_coord **coord, char *line, int cpt)
// {
// 	char 		*pos;
// 	int			i;

// 	i = 0;
// 	if (line && cpt)
// 	{
// 		while (*coord)
// 		{
// 			coord = &(*coord)->next;
// 		}
// 		while ((pos = ft_strrchr(line, '#')))
// 		{
// 			(*coord)->x[++i] = cpt;
// 			(*coord)->y[i] = pos - line;
// 			line = ft_strcpy(line, pos);
// 		}
// 		if (*coord)
// 			(*coord)->next = NULL;
// 	}
// }

t_tetri		*read_file(int fd)
{
	t_tetri	*lst;
	char	*line;
	char	*tmp;
	char	id;
	int		cpt;
	int		i;

	i = 0;
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
	lst = tetri_add(lst, tmp, id++);
	lst = coord_add(lst);
	return (lst);
}


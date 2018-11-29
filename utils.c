#include "fillit.h"
#include <stdio.h>

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
	tmp->point = point;
	tmp->tetri = ft_strsplit(line, '\n');
	tmp->id = c;
	tmp->next = NULL;
	return (lst);
}

void		coord_add(t_coord **coord, char *line, int cpt)
{
	char 		*pos;
	int			i;

	i = 0;
	if (line && cpt)
	{
		while (*coord)
		{
			coord = &(*coord)->next;
		}
		while ((pos = ft_strrchr(line, '#')))
		{
			(*coord)->x[++i] = cpt;
			(*coord)->y[i] = pos - line;
			line = ft_strcpy(line, pos);
		}
		if (*coord)
			(*coord)->next = NULL;
	}
}

t_tetri		*read_piece(int fd)
{
	t_tetri	*lst;
	t_coord *coord;
	char	*line;
	char	*tmp;
	char	id;
	int		cpt;


	cpt = 0;
	id = 'A';
	lst = NULL;
	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		if ((++cpt % 5) != 0 && line[4] != '\n' && line[5] != '\n')
			return (NULL);
		tmp = ft_strnew(ft_strlen(line));
		tmp = ft_strcpy(tmp, line);
		coord_add(&coord, line, cpt);
		if (cpt % 5 == 0)
		{
			lst = tetri_add(lst, tmp, id++, coord);
			//ft_bzero((void *)&coord, sizeof(t_coord));
			ft_memdel((void *)&tmp);
			ft_memdel((void *)&line);
		}
	}
	return (lst);
}


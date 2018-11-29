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

void		coord_add(t_coord **coord, char *line, int cpt, int *i)
{
	char 		*pos;

	if (line && cpt)
	{
		while ((*coord)->next)
			coord = &(*coord)->next;
		line = ft_strtrim(line);
		while ((line = ft_strrchr(line, '#')) && line)
		{
			printf("cpt = %d\n", cpt);
			printf("line = %s\n\n\n", line);
	//		printf("line pos - line = %lu\n\n\n", ft_strlen(line) - (pos - line));
	//		printf("line[pos - line + 1] = %c\n\n\n", line[pos - line + 1]);
			printf("pos - line  = %ld\n\n\n", pos - line);
			//ft_strcpy(line, pos + 1);
			//ft_strcpy(line, line + pos);
			(*coord)->x[*i] = cpt;
			(*coord)->y[*i] = pos - line;
			(*i)++;
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


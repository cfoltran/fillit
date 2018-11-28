#include "fillit.h"
#include <stdio.h>

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

t_tetri		*read_piece(int fd)
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
		tmp = ft_strnew(ft_strlen(line));
		tmp = ft_strcpy(tmp, line);
		if (++cpt % 5 == 0)
		{
		 	lst = tetri_add(lst, tmp, id++);
			ft_memdel((void *)&tmp);
			ft_memdel((void *)&line);
		}
	}
	return (lst);
}


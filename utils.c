#include "fillit.h"
#include <stdio.h>

void		ft_tetriadd(t_tetri **tetri, t_tetri *new)
{
	if (new && tetri)
	{
		new->next = *tetri;
		*tetri = new;
	}
}

t_tetri		*ft_tetrinew(char **tetri, char id, t_coord point)
{
	t_tetri		*result;

	if (!tetri || !id)
		return (NULL);
		if (!(result = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);

	result->tetri = tetri;
	result->id = id;
	result->point = point;
	result->next = NULL;
	return (result);
}

t_tetri		*read_piece(int fd)
{
	t_tetri	*lst;
	t_coord coord;
	char	*line;
	char	id;
	char	*pos;
	int		i;
	int		cpt;

	i = -1;
	cpt = 0;
	id = 'A';
	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if ((++cpt % 5) != 0 && line[4] != '\0' && i < 4)
			return (NULL);
		while ((pos = ft_strchr(line, '#')))
		{
			coord.x[++i] = cpt;
			coord.y[i] = pos - line;			
		}
		if (cpt % 5 == 0)
		{
			if (cpt == 5)
				lst = ft_tetrinew(&line, id, coord);
			else
				ft_tetriadd(&lst, ft_tetrinew(&line, id++, coord));
			free(line);
			i = 0;
		}
	}
	return (lst);
}


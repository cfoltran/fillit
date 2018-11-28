#include "fillit.h"
#include <stdio.h>

// void		ft_tetriadd(t_tetri **tetri, t_tetri *new)
// {
// 	if (new && tetri)
// 	{
// 		new->next = *tetri;
// 		*tetri = new;
// 	}
// }

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

// t_tetri		*ft_tetrinew(char **tetri, char id, t_coord point)
// {
// 	t_tetri		*result;

// 	if (!tetri || !id)
// 		return (NULL);
// 		if (!(result = (t_tetri*)malloc(sizeof(t_tetri))))
// 		return (NULL);

// 	result->tetri = tetri;
// 	result->id = id;
// 	result->point = point;
// 	result->next = NULL;
// 	return (result);
// }

t_tetri		*read_piece(int fd)
{
	t_tetri	*lst;
	char	*line;
	char	**tmp;
	char	id;
	int		cpt;

	cpt = 0;
	id = 'A';
	lst = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(tmp = ()))
		tmp = ft_strjoinfree(tmp, line, ft_strlen(line), 1);
		if (++cpt % 5 == 0)
		{
		 	lst = tetri_add(lst, *tmp, id++);
			ft_memdel((void *)&tmp);
			ft_memdel((void *)&line);
		}
	}
	return (lst);
}


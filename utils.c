#include "fillit.h"

t_tetri		read_piece(int fd)
{
	t_tetri	*lst;
	char	buf[BUFF_SIZE + 1];
	int 	fd;
	char	id;
	int		end;

	buf[BUFF_SIZE - 1] = '\0';
	end = 0;
	id = 'A';
	while ((read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[BUFF_SIZE] = 0;
	}
}

void		ft_tetriadd(t_tetri **tetri, t_tetri *new)
{
	if (new && tetri)
	{
		new->next = *tetri;
		*tetri = new;
	}
}

t_coord		*ft_coordnew(int x[4], int y[5])
{
	t_coord 	*result;

	if (!(result = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);

	*result->x = *x;
	*result->y = *y;
	result->next = NULL;
	return (result);
}


t_tetri		*ft_tetrinew(char	**tetri, char id, t_coord *point)
{
	t_tetri		*result;

	if (!tetri || !id || !point)
		return (NULL);
	if (!(result = (t_tetri*)malloc(sizeof(t_list))))
		return (NULL);

	result->tetri = tetri;
	result->id = id;
	result->next = NULL;
	return (result);
}

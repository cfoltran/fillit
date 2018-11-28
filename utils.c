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

	if (!(result = (t_coord)malloc(sizeof(t_coord))))
	{
		result->x = x;
		result->y = y;
	}
	result->next = NULL;
	return (result);
}


t_tetri		*ft_tetrinew(char	**tetri, char id, t_coord point)
{
	t_list		*result;

	if (!tetri || !id || !point)
		return (NULL);
	if (!(result = (t_tetri*)malloc(sizeof(t_list))))
	{
		result->tetri = tetri;
		result->id = id;
	}
	result->next = NULL;
	return (result);
}



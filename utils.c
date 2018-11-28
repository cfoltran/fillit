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


t_tetri		*ft_lstnew(char	**tetri, char id, t_coord point)
{
	t_list		*result;

	if (!tetri || !id || !point)
		return (NULL);
	if (!(result = (t_list*)malloc(sizeof(t_list))))
	{
		result->tetri = tetri;
		result->id = id;
	}
	result->next = NULL;
	return (result);
}

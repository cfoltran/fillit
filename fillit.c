#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	//t_tetri	*res;
	int 	fd;

	if (argc == 2)
	{
		char tab[4][4] =   {{'.','.','.','.'},
        	            	{'.','.','.','.'},
            	            {'.','.','.','.'},
                	        {'#','#','#','#'}};
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_exit(OPENERR, 1);
		//res = read_piece(fd);
		
		if (!check_errors(tab))
			ft_exit(GRIDERR, 1);
		// ft_putstr(*res->tetri);
		// while (res)
		// {
		// 	ft_putendl(*res->tetri);
		// 	res = res->next;
		// }
		if (close(fd) == -1)
			ft_exit(CLOSERR, 1);
	}
	else
		ft_exit(FILEERR, 1);
	return (0);
}

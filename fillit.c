#include "fillit.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);	
	}
	else
		ft_putendl(FILENAME);
	return (0);
}

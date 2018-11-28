#include "fillit.h"

int		main(int argc, char **argv)
{
	char	buf[BUFF_SIZE + 1];
	char	**tab;
	int 	fd;
	int		ret;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[ret] = 0;	
		}
	}
	else
		ft_putstr("usage: ./fillit filename\n");
	return (0);
}

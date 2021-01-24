#include "ft_cub.h"

int			main(int argc, char **argv)
{
	t_obj 	obj;
	char	*map;

	if (argc == 2)
	{
		obj = ft_parser(argv[1], &map);
	}
	else
		printf("No file name\n");
	return 0;
}

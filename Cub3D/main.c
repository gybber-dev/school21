#include "ft_cub.h"

int			main(int argc, char **argv)
{
	t_set 	set;
	char	*map;

	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], SAVE_FLAG, ft_strlen(SAVE_FLAG)))
			printf("it's necessary to save in .bmp format\n");
		else
			set = ft_parser(argv[1], &map);
	}
	else
		printf("No file name\n");
	return (0);
}


!!!!!! Необходимо ввести perror, strerror и exit
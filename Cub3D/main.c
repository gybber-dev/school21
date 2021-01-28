#include "ft_cub.h"
#include <string.h>

int			main(int argc, char **argv)
{
	t_set 	set;
	char	*map;

//	printf("sam: %d", ft_atoi(NULL));
//	printf("sam");
//	printf("sam: %d", atoi(NULL));
	if (argc == 2)
	{
		if (!ft_strncmp(argv[1], SAVE_FLAG, ft_strlen(SAVE_FLAG)))
			printf("it's necessary to save in .bmp format\n");
		else
			set = ft_parser(argv[1], &map);
	}
	else
		ft_error(22);
	return (0);
}


//!!!!!! Необходимо ввести perror, strerror и exit
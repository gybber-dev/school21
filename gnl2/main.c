#include "get_next_line.h"
#define	FILE "short.txt"

int			main(void)
{
	int		i = 0;
	int		fd = open(FILE, O_RDONLY);
	// int		fd = 1;
	char	*line;
	int		res;

	res = 1;
	while (res == 1)
	{
		res = get_next_line(fd, &line);
		printf("===[%d]: '%s'\n\n", ++i, line);
		free(line);
	}
	if (res == -1)
		printf("===ERROR\n");
//	 while (1);
}
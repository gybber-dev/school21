#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>
#include <fcntl.h> //open


#define	FILE "short.txt"

#define	FILE "short.txt"
// #define	FILE "str.txt"
// #define	FILE "0.txt"
// #define	FILE "n0.txt"
// #define	FILE "no_read.txt"
// #define	FILE "test_dir"
// #define	FILE "test_dir/dir.txt"
// #define FILE "64bit_paragraph.txt"
// #define FILE "long_line.txt"
// #define FILE "fewchar_perline.txt"



/*
valgrind --leak-check=yes ./a.out 
*/
// #define FILE "fewchar_perline.txt"

int			main(void)
{
	int		i = 0;
	int		fd = open(FILE, O_RDONLY);
	// int		fd = 1;
	char	*line;
	int		res;

	while ((res = get_next_line(fd, &line)) == 1 || res == 0)
	{
		printf("===[%d]: '%s'\n\n", ++i, line);
		if (res == 0)
			break ;

		free_mem(&line, &line);
	// free_mem(&line);
	}
	if (res == -1)
		printf("===ERROR\n");
	// while (1);
}
#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h> //open


 #define	FILE "short.txt"
// #define	FILE "str.txt"
// #define	FILE "0.txt"
// #define	FILE "n0.txt"
// #define	FILE "no_read.txt"
// #define	FILE "test_dir"
// #define	FILE "test_dir/dir.txt"
//#define FILE "64bit_paragraph.txt"
//#define FILE "only_newline.txt"
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
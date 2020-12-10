#include <stdio.h>
#include "get_next_line_bonus.h"
#include <fcntl.h> //open


 #define	FILE1 "short.txt"
 #define	FILE2 "str.txt"
 #define	FILE3 "0.txt"
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
	int		fd;
	char	*line;
	int		res;
	int		fds = 2;

	res = 1;
	fd = open(FILE1, O_RDONLY);
	while(fds)
	{
		if (fds == 2)
			fd = open(FILE2, O_RDONLY);
		else if (fds == 1)
			fd = open(FILE1, O_RDONLY);
		else if (fds == 3)
			fd = open(FILE3, O_RDONLY);
		while (res == 1 && i <= 3)
		{
			res = get_next_line(fd, &line);
			printf("[%d]===[%d]: '%s'\n\n", fd, ++i, line);
			free(line);
		}
		fds--;
		i = 0;
	}
	if (res == -1)
		printf("===ERROR\n");
	 while (1);
}
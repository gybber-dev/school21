#include <stdio.h>
#include "get_next_line.h"

int main (void)
{
	char *str = ft_strdup("hey!");
	printf("'%s'\n", str);
	free(str);
	printf("'%s'\n", str);
}
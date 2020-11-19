#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>

void	free_mem(char **mem)
{
	if (*mem != NULL)
		free(*mem);
	*mem = NULL;
}

int main (void)
{
	int N = 5;
	char *str = (char *)malloc(N);
	memcpy(str, "asdf", N);
	str[N - 1] = 0;
	printf("sizeof: '%s' is [%lu]\n", str, sizeof(str));
	free_mem(&str);
	printf("sizeof: '%s' is [%lu]\n", str, sizeof(str));
	free_mem(&str);
	printf("'%s'\n", str);
}
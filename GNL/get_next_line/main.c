#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>

void	free_mem(char **arg1, char **arg2, char arg3, char arg4)
{
	if (!arg1)
		printf("arg1 not defined\n");
	if (!arg2)
		printf("arg2 not defined\n");
	if (!arg3)
		printf("arg3 not defined\n");
	if (!arg4)
		printf("arg4 not defined\n");
}

int main (void)
{
	char *str1 = "str1";
	free_mem(&str1, &NULL, &NULL, &NULL);
}
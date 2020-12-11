#include <stdio.h>

int		main(void)
{
	printf("orig printf: %0*.*d\n", 15, 5, -321);
	printf("'value of number': %-*.5s\n", 4, "value of number");
	printf( "%0*x\n", 8, 15 );
}
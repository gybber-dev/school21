#include <stdio.h>
#include <stdarg.h>

void			myfun(char *s, ...)
{
	va_list		p;
	va_start(p, s);
	printf("vars: %d\n", va_arg(p, int));
	printf("vars: %d\n", va_arg(p, int));
	printf("vars: %s\n", va_arg(p, char*));
	printf("vars: %d\n", va_arg(p, int));
	va_end(p);
}

int		main(void)
{
	printf("orig printf: %0*.*d\n", 15, 5, -321);
	printf("'value of number': %-*.5s\n", 4, "value of number");
	printf( "%0*x\n", 8, 15 );
	myfun("hi", 1, 2, "3asdf", 4);
}
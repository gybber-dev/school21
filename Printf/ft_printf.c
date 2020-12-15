#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_struct	obj;

	printf("PRINT STRING: '%s'\n", str);
	va_start(p, str);
	obj = ft_parse(str);
	printf("\tobj.flags: %d\n", obj.flags);
	va_end(p);
	return (-1);
}
#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_obj		obj;

	printf("PRINT STRING: '%s'\n", str);
	va_start(p, str);
//	while (*str)
//	{
//		if (*str == '%')
//		{
//		}
//	}
	obj = ft_parse(str, p);
	ft_processor(&obj, p);
	DEBUG printf("\tobj.flags: %d\n", obj.s_precision.numb);
	va_end(p);
	return (-1);
}
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
	obj = ft_parse(str);
	printf("\tobj.flags: %zd\n", obj.s_flag.size);
	va_end(p);
	return (-1);
}
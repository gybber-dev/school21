#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_obj		obj;
	char		*res;

	printf("PRINT STRING: '%s'\n", str);
	va_start(p, str);
	while (*str)
	{
		if (*str == '%' && *(++str) != '%' )
		{
			obj = ft_parse(&str, p);
			res = ft_processor(&obj, p);
			ft_putstr_fd(res, 1);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	DEBUG printf("\tobj.flags: %d\n", obj.s_precision.numb);
	va_end(p);
	return (-1);
}
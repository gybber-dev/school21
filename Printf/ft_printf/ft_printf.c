#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_obj		obj;
	char		*res;
	int			res_num;
	const char	*begin;

	DEBUG printf("PRINT STRING: '%s'\n", str);
	va_start(p, str);
	res_num = 0;
	begin = str;
	while (*str)
	{
		if (*str == '%' && *(++str) != '%' )
		{
			obj = ft_parse(&str, p);
			res = ft_processor(&obj, p);
			if (res == NULL)
			{
				//	grustno....
				break ;
			}
			ft_putstr_fd(res, 1);
			res_num += ft_strlen(res);
		}
		else
		{
			res_num++;
			write(1, str, 1);
		}
		str++;
	}
	DEBUG printf("\tobj.flags: %d\n", obj.s_precision.numb);
	va_end(p);
	return (res_num);
}
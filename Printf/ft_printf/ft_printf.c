#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		p;
	t_obj		obj;
	char		*res;
	int			res_num;

	DEBUG printf("PRINT STRING: '%s'\n", str);
	va_start(p, str);
	res_num = 0;
	while (*str)
	{
		if (*str == '%' && *(str++) != '\0')
		{
			obj = ft_parse(&str, p);
			DEBUG printf("Is parser correct (type is on)? [%d]\n", obj.s_type.on);
			res = obj.s_type.on ? ft_processor(&obj, p) : NULL;
			if (res == NULL)
			{
				//	grustno.... ( ! )
				printf("ERROR DETECTED\n");
				res_num = -1;
				ft_free(&res);
				break ;
			}
			write(1, res, obj.len);
			res_num += obj.len;
			ft_free(&res);
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
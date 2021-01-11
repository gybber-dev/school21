#include "../ft_printf.h"

char			*ft_processor(t_obj *obj, va_list p)
{
	char		*res;
	char		*tmp;
	DEBUG printf("PROCESSOR\n\ttype: %d\n", obj->s_type.on);
//	printf("%d\n", va_arg(p, int));
//	int			str_len;

	if (obj->s_type.numb == 'd' || obj->s_type.numb == 'i')
		res = ft_int(obj, va_arg(p, int));
	if (obj->s_type.numb == 'u')
		res = ft_u(obj, va_arg(p, unsigned int ));
	if (obj->s_type.numb == 'x' || obj->s_type.numb == 'X')
		res = ft_x(obj, va_arg(p, unsigned int));
	if (obj->s_type.numb == 'c')
		res = ft_char(obj, va_arg(p, int));
	if (obj->s_type.numb == 's' || obj->s_type.numb == '%')
	{
		tmp = (obj->s_type.numb == '%') ? ft_strdup("%") : va_arg(p, char*);
		if (!tmp)
		{

			/*grustno*/
			;
		}
		DEBUG printf("for type 's' or '%%': '%s'\n", tmp);
		res = ft_s(obj, &tmp);
	}
	if (obj->s_type.numb == 'p')
	{
		tmp = va_arg(p, char*);
		DEBUG printf("for type 's': '%s'\n", tmp);
		res = ft_p(obj, &tmp);
	}
	return (res);
}
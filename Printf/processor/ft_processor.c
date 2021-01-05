#include "../ft_printf.h"

char			*ft_processor(t_obj *obj, va_list p)
{
	char		*res;
	DEBUG printf("PROCESSOR\n\twidth: %c\n", obj->s_width.numb);
//	printf("%d\n", va_arg(p, int));
//	int			str_len;

	if (obj->s_type.numb == 'd' || obj->s_type.numb == 'i')
		res = ft_int(obj, va_arg(p, int));
	if (obj->s_type.numb == 'u')
		res = ft_u(obj, va_arg(p, int));

	return (res);
}
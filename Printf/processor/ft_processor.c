#include "../ft_printf.h"

void			ft_processor(t_obj *obj, va_list p)
{
	DEBUG printf("PROCESSOR\n\twidth: %c\n", obj->s_width.numb);
//	printf("%d\n", va_arg(p, int));
//	int			str_len;

	if (obj->s_type.numb == 'd')
		ft_int(obj, va_arg(p, int));

}
#include "../ft_printf.h"

void			ft_processor(t_obj *obj, va_list p)
{
	printf("PROCESSOR\n\twidth: %d\n", obj->s_width.numb);
	printf("%d\n", va_arg(p, int));
}
#include "../ft_printf.h"

static void		ft_init_flag(t_part *flag)
{
	flag->numb = 0;
	flag->on = 0;
}

void			ft_init_obj(t_obj *obj)
{
	DEBUG printf("INIT OBJ: type: [%c]\t", obj->s_type.numb);
	ft_init_flag(&obj->s_flag);
	ft_init_flag(&obj->s_width);
	ft_init_flag(&obj->s_precision);
	ft_init_flag(&obj->s_type);
	obj->len = 0;
	DEBUG printf(" ->\ttype: [%c]\n", obj->s_type.numb);
	return ;
}
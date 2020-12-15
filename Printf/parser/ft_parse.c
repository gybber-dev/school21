#include "../ft_printf.h"

static void		check_flag(const char **str, t_struct *obj)
{
	printf("CHECK FLAG: ('%s', %d)\n", *str, obj->flags);

	while (**str == '-' || **str == '0')
	{
		printf("\tflag is detected\n");
		obj->flags = 1;
		/*
		 * Read about struct in struct!
		 * obj->flag->on = 1
		 * obj->flag->size++;
		 * ....
		 * */
		(*str)++;
	}
	return ;
}

//void 			check_width(char **str, t_struct *obj)
//{
//	return ;
//}
//
//void 			check_precision(char **str, t_struct *obj)
//{
//	return ;
//}
//
//void 			check_type(char **str, t_struct *obj)
//{
//	return ;
//}

t_struct		ft_parse(const char *str)
{
	t_struct	obj;

	printf("PARSER: ('%s')\n\n", str);
	while (*str)
	{
		if (*str++ == '%')
		{
			check_flag(&str, &obj);
//			check_width(*str, obj);
//			check_precision(*str, obj);
//			check_type(*str, obj);
		}
		str++;
	}
	return (obj);
}
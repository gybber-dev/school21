#include "../ft_printf.h"

static void		check_flag(const char **str, t_obj *obj)
{
	printf("\nCHECK FLAG: ('%s')\n", *str);

	while (**str == '-' || **str == '0')
	{
		printf("\tflag is detected\n");
		obj->s_flag.val = **str;
		obj->s_flag.size++;

		(*str)++;
	}
	return ;
}

static void		check_width(const char **str, t_obj *obj)
{
	printf("\nCHECK WIDTH: ('%s')\n", *str);

	int is_only;

	is_only = 2;
	while ((**str == '*' && is_only == 2) || (ft_isdigit(**str) && is_only != 1))
	{
		printf("\twidth [%c] is detected\n", **str);
		obj->s_width.val = **str;
		is_only = (**str == '*')? 1 : 0;
		(*str)++;
	}
	return ;
}
//
//static void		check_precision(const char **str, t_struct *obj)
//{
//	printf("CHECK FLAG: ('%s', %zd)\n", *str, obj->s_flag.size);
//	return ;
//}
//
//static void		check_type(char **str, t_struct *obj)
//{
//	printf("CHECK FLAG: ('%s', %zd)\n", *str, obj->s_flag.size);
//	return ;
//}

t_obj			ft_parse(const char *str)
{
	t_obj		obj;

	printf("PARSER: ('%s')\n\n", str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check_flag(&str, &obj);
			check_width(&str, &obj);
//			check_precision(*str, obj);
//			check_type(*str, obj);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	return (obj);
}
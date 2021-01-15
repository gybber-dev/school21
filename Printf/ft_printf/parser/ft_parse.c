#include "../ft_printf.h"

/*
** All check functions MUST put the pointer to the next character!
*/
static void		parse_flag(const char **str, t_obj *obj)
{
	DEBUG printf("\nCHECK FLAG: ('%s')\n", *str);

	while (**str == '-' || **str == '0')
	{
		DEBUG printf("\tflag is detected\n");
		if (**str == '0' && obj->s_flag.on == 1)
		{
			(*str)++;
			continue ;
		}
		obj->s_flag.on = 1;
		obj->s_flag.numb = **str;
		(*str)++;
	}
	return ;
}

static void		parse_width(const char **str, t_obj *obj, va_list p)
{
	DEBUG printf("\nCHECK WIDTH: ('%s')\n", *str);
	int			flag;

	flag = 0;
	while (**str == '*' || ft_isdigit(**str))
	{
		obj->s_width.on = 1;
		if (**str == '*' && !flag)	// only first *
		{
			flag = 1;
			obj->s_width.numb = va_arg(p, int);
		}
		else if (flag != 1)			// first and following digits
		{
			obj->s_width.numb = obj->s_width.numb * 10 + (**str) - '0';
		}
		(*str)++;
	}

	DEBUG printf("\twidth: '%d'\n", obj->s_width.numb);
	return ;
}

static void		parse_precision(const char **str, t_obj *obj, va_list p)
{
	int			flag;

	flag = 0;
	DEBUG printf("CHECK PRECISION: ('%s')\n", *str);
	//

//	!!!!add for multiple dots!!!!!

	//
	if (**str == '.')
	{
		obj->s_precision.on = 1;
		obj->s_precision.numb = 0;
		DEBUG printf("\tprecision [%c] is detected\n", **str);
		while (*(++(*str)) == '*' || ft_isdigit(**str))
		{
			obj->s_precision.on = 1;
			if (**str == '*' && flag != 2)	// only first *
			{
				flag = 2;
				obj->s_precision.numb = va_arg(p, int);
			}
			else if (flag != 2)			// first and following digits
			{
				obj->s_precision.numb = obj->s_precision.numb * 10 + (**str) - '0';
				flag = 1;
			}
		}
	}
	DEBUG printf("\tprecision: '%d'\n", obj->s_precision.numb);
	return ;
}

static void		parse_type(const char **str, t_obj *obj)
{
	DEBUG printf("CHECK TYPE: ('%s')\n", *str);
	if (ft_strchr(SUBJ_TYPES, **str))
	{
		DEBUG printf("\ttype [%c] is detected\n", **str);
		obj->s_type.numb = **str;
		obj->s_type.on = 1;
	}
	DEBUG printf("\ttype: '%d'\n", obj->s_type.numb);
	return ;
}

t_obj			ft_parse(const char **str, va_list p)
{
	t_obj		obj;

	DEBUG printf("PARSER: ('%s')\n\n", *str);
	ft_init_obj(&obj);
	if (**str)
		parse_flag(str, &obj);
	if (**str)
		parse_width(str, &obj, p);
	if (**str)
		parse_precision(str, &obj, p);
	if (**str)
		parse_type(str, &obj);

	// Additional rules:

	// 0. Если указан отрицательный модификатор точности, то считается, что
	// модификатор точности отсутствует.
	if (obj.s_precision.on && obj.s_precision.numb < 0)
	{
		DEBUG printf("Incorrect precision!!! Kill it\n");
		obj.s_precision.on = 0;
		obj.s_precision.numb = 0;
	}
	// 1. Для типов d, i, o, u, x, X, если точность указана, флаг '0' игнорируется
	if (obj.s_flag.on && obj.s_flag.numb == '0' && obj.s_precision.on && obj.s_type.on &&
			ft_strchr("diouxX", obj.s_type.numb))
	{
		DEBUG printf("null the flag!!!!\n");
		obj.s_flag.on = 0;
		obj.s_flag.numb = 0;
	}
//	// 1.1. Флаг '0' используется только для типов
//	// d, i, o, u, x, X, a, A, e, E, f, F, g, G
//	if (obj.s_flag.on && obj.s_flag.numb == '0'
//		&& !ft_strchr("diouxXaAeEfFgG", obj.s_type.numb))
//	{
//		DEBUG printf("flag 0 for wrong type!!!!\n");
//		obj.s_flag.on = 0;
//		obj.s_flag.numb = 0;
//	}
	// 2. Если указан отрицательный модификатор ширины, считается что выставлен
	// флаг -, а значение модификатора ширины установлено абсолютным
	if (obj.s_width.on && obj.s_width.numb < 0)
	{
		DEBUG printf("width < 0!!!!\n");
		obj.s_flag.on = 1;
		obj.s_flag.numb = '-';
		obj.s_width.numb *= -1;
	}
	DEBUG printf("PARSER:\n\tflag[%d]: %d\n\twidth[%d]: %d\n\tprec[%d]: %d\n\ttype[%d]: %c\n",
			  obj.s_flag.on, obj.s_flag.numb, obj.s_width.on, obj.s_width.numb,
			  obj.s_precision.on, obj.s_precision.numb, obj.s_type.on, obj.s_type.numb);
	return (obj);
}
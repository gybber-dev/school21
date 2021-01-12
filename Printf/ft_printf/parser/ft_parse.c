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
		obj->s_flag.size++;
		(*str)++;
	}
	return ;
}

static void		parse_width(const char **str, t_obj *obj, va_list p)
{
	DEBUG printf("\nCHECK WIDTH: ('%s')\n", *str);
	obj->s_width.type = 0;
	obj->s_width.numb = 0;
	while (**str == '*' || ft_isdigit(**str))
	{
		obj->s_width.on = 1;
		if (**str == '*' && obj->s_width.type == 0)	// only first *
		{
			obj->s_width.type = 2;
			obj->s_width.numb = va_arg(p, int);
			//	Add:
			//	Если этим способом указан отрицательный модификатор ширины,
			//	считается что выставлен флаг -, а значение модификатора ширины
			//	установлено абсолютным.
		}
		else if (obj->s_width.type != 2)			// first and following digits
		{
			obj->s_width.numb = obj->s_width.numb * 10 + (**str) - '0';
			obj->s_width.type = 1;
		}
		(*str)++;
	}

	DEBUG printf("\twidth: '%d'\n", obj->s_width.numb);
	return ;
}

static void		parse_precision(const char **str, t_obj *obj, va_list p)
{
	DEBUG printf("CHECK PRECISION: ('%s')\n", *str);
	obj->s_precision.type = 0;
	obj->s_precision.numb = 0;
	//

//	!!!!add for multiple dots!!!!!

	//
	if (**str == '.')
	{
		obj->s_precision.on = 1;
		obj->s_precision.type = 0;
		obj->s_precision.numb = 0;
		DEBUG printf("\tprecision [%c] is detected\n", **str);
		while (*(++(*str)) == '*' || ft_isdigit(**str))
		{
			obj->s_precision.on = 1;
			if (**str == '*' && obj->s_precision.type == 0)	// only first *
			{
				obj->s_precision.type = 2;
				obj->s_precision.numb = va_arg(p, int);
			}
			else if (obj->s_precision.type != 2)			// first and following digits
			{
				obj->s_precision.numb = obj->s_precision.numb * 10 + (**str) - '0';
				obj->s_precision.type = 1;
			}
			obj->s_precision.size++;
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
	const char	*p_f;

	DEBUG printf("PARSER: ('%s')\n\n", *str);
	ft_init_obj(&obj);
	p_f = *str;
	if (**str)
		parse_flag(str, &obj);
	if (**str)
		parse_width(str, &obj, p);
	if (**str)
		parse_precision(str, &obj, p);
	if (**str)
		parse_type(str, &obj);

	// Additional rules:

	// 1. Для типов d, i, o, u, x, X, если точность указана, флаг '0' игнорируется
	if (obj.s_flag.on && obj.s_flag.numb == '0' && obj.s_precision.on && obj.s_type.on &&
			ft_strchr("diouxX", obj.s_type.numb))
	{
		DEBUG printf("null the flag!!!!\n");
		obj.s_flag.on = 0;
		obj.s_flag.numb = 0;
	}
	DEBUG printf("str: '%s'\nflag[%d]: %c;\nwidth: %d\nprecis: %d\ntype: %c\n", \
	p_f, obj.s_flag.on, obj.s_flag.numb, obj.s_width.numb, obj.s_precision.numb, obj.s_type.numb);
	return (obj);
}
#include "../ft_printf.h"

/*
** All check functions MUST put the pointer to the next character!
*/
static void		check_flag(const char **str, t_obj *obj)
{
	printf("\nCHECK FLAG: ('%s')\n", *str);

	while (**str == '-' || **str == '0')
	{
		printf("\tflag is detected\n");
		obj->s_flag.numb = **str;
		obj->s_flag.size++;

		(*str)++;
	}
	return ;
}

static void		check_width(const char **str, t_obj *obj, va_list p)
{
	printf("\nCHECK WIDTH: ('%s')\n", *str);
	obj->s_width.type = 0;
	obj->s_width.numb = 0;
	while (**str == '*' || ft_isdigit(**str))
	{
		obj->s_width.on = 1;
		if (**str == '*' && obj->s_width.type == 0)	// only first *
		{
			obj->s_width.type = 2;
			obj->s_width.numb = va_arg(p, int);
		}
		else if (obj->s_width.type != 2)			// first and following digits
		{
			obj->s_width.numb = obj->s_width.numb * 10 + (**str) - '0';
			obj->s_width.type = 1;
		}
		(*str)++;
	}
	printf("\twidth: '%d'\n", obj->s_width.numb);
	return ;
}

static void		check_precision(const char **str, t_obj *obj, va_list p)
{
	printf("CHECK PRECISION: ('%s')\n", *str);

	//

//	!!!!add for multiple dots!!!!!

	//
	if (**str == '.')
	{
		obj->s_precision.on = 1;
		obj->s_precision.type = 0;
		obj->s_precision.numb = 0;
		printf("\tprecision [%c] is detected\n", **str);
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
	printf("\tprecision: '%d'\n", obj->s_precision.numb);
	return ;
}

static void		check_type(const char **str, t_obj *obj)
{
	printf("CHECK TYPE: ('%s')\n", *str);
	if (ft_strchr(SUBJ_TYPES, **str))
	{
		printf("\ttype [%c] is detected\n", **str);
		obj->s_type.numb = **str;
	}
	printf("\ttype: '%d'\n", obj->s_type.numb);
	return ;
}

t_obj			ft_parse(const char *str, va_list p)
{
	t_obj		obj;
	const char	*p_f;

	printf("PARSER: ('%s')\n\n", str);
	while (*str)
	{
		if (*str == '%' && *(++str) != '%' )
		{
			p_f = str;
			check_flag(&str, &obj);
			check_width(&str, &obj, p);
			check_precision(&str, &obj, p);
			check_type(&str, &obj);
			printf("str: '%s'\nflag: %c;\nwidth: %d\nprecis: %d\ntype: %c\n", \
			p_f, obj.s_flag.numb, obj.s_width.numb, obj.s_precision.numb, obj.s_type.numb);
		}
		else
		{
			write(1, str, 1);
		}
		str++;
	}
	return (obj);
}
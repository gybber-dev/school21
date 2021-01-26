#include "../libft/libft.h"
#include <stdio.h>

int				reg_test(char *rule, char c)
{
	if (*rule == '\\' && *(rule + 1) == 'd')
		return (ft_isdigit(c));
	else
		return (*rule == c ? 1 : 0);
}




/*
** Get pointer to string (str) and find the symbol defined in argument rule.
** Returns pointer to the next symbol after rule (if it was).
** If length(c) == 1 - pass the symbols defined in c;
** If length(c) == 2 - symbol class is defined:
** Symbol classes:
** \d - digits
** \s -
*/

char			*reg_find_symbol(char *str, char *rule)
{
	char		*res;

	if (*rule == '\\' && *(rule + 1) == 'd')
	{
//		printf("check0\n");
		while (!ft_isdigit(*str))
			str++;
		return (str);
	}
	else
	{
//		printf("check1\n");
		return (ft_strchr(str, *rule));
	}
	return (NULL);
}

/*
** Get pointer to string (str) and pass all symbols defined in argument c.
** Returns pointer to the next symbol after c (if it was).
** If length(c) == 1 - pass the symbols defined in c;
** If length(c) == 2 - symbol class is defined:
** Symbol classes:
** \d - number
** \s -
*/
char			*reg_pass_string(char *str, char *rule)
{
	int			flag;
	char		*res;
	char		*rule0;
	int			rule_step;

	res = NULL;
	rule0 = rule;
	while (*rule)
	{
		while (*str)
		{
			if (*rule == 0) {
				break;
			}
			rule_step = (*rule == '\\') ? 2 : 1;
			printf("find: '%.*s'\n", rule_step, rule);
			printf("in string: '%s'\n\n", str);
			if (rule_step == 1 && reg_test(rule, *str))
				rule += rule_step;
			else if(rule_step == 2 && reg_test(rule, *str))
			{
				while(reg_test(rule, *str))
					str++;
				rule += rule_step;
				str--;
			}
			else
			{
				rule = rule0;
			}
			str++;
		}
		break ;
	}
	return (str);
}


int main()
{
	char *str = "R asfsdfs s";
	char *rule = "\\d ";
	printf("rule: '%s'\n%s\n", rule, str);
//	str = reg_find_symbol(str, rule);
//	printf("found is : '%s'\n", str);
	str = reg_pass_string(str, rule);
	printf("passed to: '%s'\n", str);
}


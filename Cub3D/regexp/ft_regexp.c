#include "ft_regexp.h"
//#include <stdio.h>

/*
** REGEXP LITE IMPLEMENTATION:
** Symbol classes:
** \d - any number [1, 10, 432, ..]
** \s -
*/

int				reg_test(char *rule, char c)
{
	if (*rule == '\\' && *(rule + 1) == 'd')
		return (ft_isdigit(c));
	else
		return (*rule == c ? 1 : 0);
}

/*
** Returns pointer to the match rule in string.
*/

char			*reg_find_symbol(char *rule, char *str)
{
	char		*res;

	while (*str)
	{
		if (!reg_test(rule, *str))
			str++;
		else
			return (str);
	}
	return (NULL);
}

/*
** Get pointer to string (str) and pass all symbols defined in 'rules'.
** Returns pointer to the next symbol after the rule passed string.
*/
char			*reg_pass_string(char *rule, char *str)
{
	char		*rule0;
	int			rule_step;

	rule0 = rule;
	while (*rule)
	{
		while (*str)
		{
			if (*rule == 0)
				break;
			rule_step = (*rule == '\\') ? 2 : 1;
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
				rule = rule0;
			str++;
		}
		break ;
	}
	return (*str ? str : NULL);
}


//int main()
//{
//	char *str = "F 220,100,0";
//	char *rule = " \\d";
////	printf("rule: '%s'\n%s\n", rule, str);
////	str = reg_pass_string(rule, str);
////	printf("passed to: '%s'\n", str);
//	str = reg_find_symbol(rule, str);
//	printf("found: '%s'\n", str);
//}


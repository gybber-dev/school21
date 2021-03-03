#include "libft.h"

/*
** returns N [times] times repeated string [*c]
** 	NULL on error
*/
char			*ft_strmultiply(char *c, size_t times)
{
	char		*res;
	char		*tmp;

	res = NULL;
	if (times == 0)
		return (ft_strdup(""));
	while (times--)
	{
		tmp = res;
		if (!(res = ft_strjoin(c, res)))
		{
			if (tmp)
				free(tmp);
			break ;
		}
		if (tmp)
			free(tmp);
	}
	return (res);
}
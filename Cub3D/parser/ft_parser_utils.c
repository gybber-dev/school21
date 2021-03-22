#include "../ft_cub.h"

int				is_map(char *str)
{
	if (!(*str))
		return (0);
	while (*str)
	{
		if (!ft_strchr("102 NEWS", *str))
			return (0);
		str++;
	}
	return (1);
}
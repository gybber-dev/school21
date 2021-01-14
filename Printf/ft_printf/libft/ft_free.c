#include "libft.h"

int		ft_free(char **mem)
{
	if (!(*mem))
	{
		free(*mem);
		*mem = NULL;
	}
	return (1);
}

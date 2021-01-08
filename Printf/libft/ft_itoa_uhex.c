#include "libft.h"

static char		ft_hex(unsigned int n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else if (n == 15)
		return ('f');
	else
		return (n + '0');
}

static size_t	count_len(unsigned int n)
{
	if (n < 16)
		return (1);
	return (count_len(n / 16) + 1);
}

char			*ft_itoa_uhex(unsigned long int n)
{
	size_t		len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len + 1);
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = (n < 0) ? ft_hex(- n % 16) : ft_hex(n % 16);
		n = n / 16;
	}
	return (str);
}

#include <stdio.h>
#include "ft_printf.h"

static size_t	count_len(unsigned long int n)
{
	if (n < 16)
		return (1);
	return (count_len(n / 16) + 1);
}

static char	ft_hex0(int n)
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

static int	ft_num2(unsigned long int l)
{
	int		a;

	a = 0;
	if (l > 0)
	{
		while (l != 0)
		{
			l = l / 16;
			a++;
		}
		a++;
	}
	else
		a = 2;
	return (a);
}

char		*ft_itoahexunl(unsigned long int n)
{
	char	*p;
	int		num;

	num = ft_num2(n);
	p = malloc(sizeof(char) * num);
	if (!p)
		return (NULL);
	p[--num] = '\0';
	while (num--)
	{
		p[num] = ft_hex0(n % 16);
		n /= 16;
	}
	return (p);
}

char			*ft_itoa_uhex0(unsigned long int n)
{
	int			len;
	char		*str;

	len = count_len(n);
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	str[len - 1] = '\0';
	str[0] = (n == 0) ? '0' : str[0];
	while (len-- && n != 0)
	{
		str[len] = ft_hex0(n % 16);
		n = n / 16;
	}
	return (str);
}

int main(void)
{
	char *val  = "hello";
	long unsigned int numb = (long unsigned int)&(*val);
	int n = 100000000000;
//	printf("%X\n", c);
//	printf("%X\n", (unsigned char)c);
//	printf("%hhX\n", c);
	printf("orig: '%s'\n", ft_itoahexunl(numb));
	printf("orig: '%s'\n", ft_itoa_uhex0(numb));
}
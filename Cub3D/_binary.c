#include <stdio.h>
#include <string.h>
#include "libft/libft.h"

int		create_trgb(int t, int r, int g, int b)
{
	return(t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main()
{
	printf("%s\n\n", ft_strnstr("R DJDJDJDJJD", "R ", 2));
	printf("%.8X\n", create_trgb(50, 220, 100, 10));
}
#include "ft_cub.h"

int		create_trgb(int t, int r, int g, int b)
{
	printf("TRGB: %d\t%d\t%d\n", r, g, b);
	return(t << 24 | r << 16 | g << 8 | b);
}
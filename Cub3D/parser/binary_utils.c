#include <stdio.h>
int		create_trgb(int t, int r, int g, int b)
{
	printf("TRGB: %d\t%d\t%d\n", r, g, b);
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

//F 220,100,0		14443520
//C 225,30,0		14753280
//int main(void)
//{
//	printf("num: '%d'\n", create_trgb(0,220,100,0));
//	printf("num: '%d'\n", create_trgb(0,225,30,0));
//}

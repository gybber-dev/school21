#include <stdio.h>

/*
**	Setting a bit:
**		number |= 1UL << n;
**	Clearing a bit:
**		number &= ~(1UL << n);
**	Toggling a bit:
**		number ^= 1UL << n;
**	Checking a bit:
**		bit = (number >> n) & 1U;
**	Changing the nth bit to x:
**		number ^= (-x ^ number) & (1UL << n);
*/

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

void printBits(size_t const size, void const * const ptr)
{
	unsigned char *b = (unsigned char*) ptr;
	unsigned char byte;
	int i, j;

	for (i = size-1; i >= 0; i--) {
		for (j = 7; j >= 0; j--) {
			byte = (b[i] >> j) & 1;
			printf("%u", byte);
		}
	}
	puts("");
}


//F 220,100,0		14443520
//C 225,30,0		14753280
int main(void)
{
//	printf("num: '%d'\n", create_trgb(0,220,100,0));
//	printf("num: '%d'\n", create_trgb(0,225,30,0));

	int move = 0;
	int W_BIT = 1;
	int A_BIT = 2;

	printBits(sizeof(move), &move);
	move |= 1 << W_BIT;
	printBits(sizeof(move), &move);
	move |= 1 << A_BIT;
	printBits(sizeof(move), &move);
	move &= ~(1 << A_BIT);
	printf("total: ");
	printBits(sizeof(move), &move);
}

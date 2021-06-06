#include <unistd.h>
#include <term.h>
#include <stdio.h>
#include <string.h>



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

int main(int argc, char *argv[], char *env[])
{
	char str[2000];
	int l;
	struct termios term;

//	int tcgetattr(int fd, struct termios *termios_p);
//	int tcsetattr(int fd, int action, struct termios *termios_p);
//	int tcdrain(int fd);
//	int tcflush(int fd, int queue);
//	int tcflow(int fd, int action);

	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO);	//not show symbols
	term.c_lflag &= ~(ICANON); // no-canonical mode (print and end)
	term.c_cc[VMIN] = 2;
	term.c_cc[VTIME] = 255; // сколько read будет ждать прежде чем завершиться
	tcsetattr(0, TCSANOW, &term);

	/*
	 * У нас есть терминал. Его версия прописывается в env -> TERM.
	 * Посколько термакапы - база данных, содержащая настройки терминала, то необходимо
	 * подключить пакет для работы с "нашим" терминалом
	 * */
	tgetent(0, term_name);
	char *s = key_f15



	do{
		l = read(0, str, 100);
		write(1, str, l);
	}while(strcmp(str, "\n"));
	l = read(0, str, 100);
	write(1, str, l);
	write(1, "\n", 1);
//	printf("%lu\n", term.c_cflag);
	return 0;

}
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>


int lsh_launch(char **args)
{
	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0) {
		// Дочерний процесс
		printf("daughter\n");
		if (execvp(args[0], args) == -1) {
			perror("lsh");
			printf("some error in daughter\n");

		}
		exit(EXIT_FAILURE);
	} else if (pid < 0) {
		// Ошибка при форкинге
		perror("lsh");
		printf("some error\n");
	} else {
		// Родительский процесс
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
			printf("status: %d\n", status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		printf("parent\n");
	}

	return 1;
}


int main(int argc, char **agrv, char **env)
{
	lsh_launch(NULL);
}

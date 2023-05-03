#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	char *const paramList[] = {"/bin/ls", "-l", ".", NULL};
	if ((pid = fork()) == -1)
		perror("Fork Error");
	else if (pid == 0) {
		execv("/bin/ls", paramList);
	}
}

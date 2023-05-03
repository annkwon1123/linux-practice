#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int pid;

	/* 새로운 자식을 fork 한다. */
	pid = fork();

	if (pid == 0) { /* 자식 프로세스 */
		printf("Child of %d is %d\n", getpid(), getpid());

	}else { /* 부모 프로세스 */
		/* parent will wait for the child to complete */
		printf("I am %d. My child is %d\n", getpid(), pid);
	}

	return 0;
}

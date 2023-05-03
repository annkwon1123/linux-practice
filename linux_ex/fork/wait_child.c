#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int main() {
  int pid;
  int status;
  int retval;

  pid = fork();
  if (pid < 0) {
    perror("FORK ERROR:");
    exit(0);
  }

  if (pid == 0) { // 자식 프로세스
    int i;
    for (i = 0; i < 10; i++) {
      printf("Child : %d\n", i);
      sleep(3);
    }
    exit(3);
  } else {
    // 부모프로세스는 자식프로세스가 종료할 때까지 기다린다.
    printf("Waiting for Child process (pid:%d)\n", pid);
    retval = waitpid(pid, &status, 0);
    printf("Child exits (status:%d)\n", status); 
    // status 값만 가지고는 어떻게 종료되었는지 알 수 없으므로 다음과 같은 매크로 함수를 통해 검사해야 한다.

    // 자식 프로세스가 어떤 정보를 반환하며 종료되었느지 확인한다.
    if (retval > 0) { // 자식 프로세스가 에러 없이 정상적으로 종료했다.
      if (WIFEXITED(status)) { // 자식 프로세스가 정상종료되었을 때
        printf("Child exited by process completeion : %d\n", WEXITSTATUS(status));
      }
      if (WIFSIGNALED(status)) { // 자식 프로세스가 시그널에 의해 종료되었을 때
        printf("Child exited by signal : %d\n", WTERMSIG(status));
	/*
	 * 시그널을 한번 보내보도록 해보자. 
	 *
	 * ./wait_child
	 *
	 * 다른 터미널을 열어서 자식 프로세스 pid 정보를 가지고 프로세스를 죽인다.
	 *
	 * kill -9 {pid}
	 *
	 */
      }
    } else { // 자식 프로세스 에러가 발생했다.
        printf("Unexpected error.\n");
	exit(0);
    }
  }
  return 0;
}

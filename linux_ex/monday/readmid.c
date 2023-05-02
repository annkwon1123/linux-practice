#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
	if (argc < 2) exit(0);
	int fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("[ERR] open\n");
		exit(0);
	}
	char buf[BUF_SIZE];
	sprintf(buf, "%s", "If I have seen futher it is by standing on the shoulders of Giants.");
	write(fd, buf, BUF_SIZE);
	return 0;
}

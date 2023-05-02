#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char* argv[]) {
	if (argc < 3) exit(0);
	int fd = open(argv[1], O_RDWR);
	if (fd < 0) {
		perror("[ERR] open\n");
		exit(0);
	}
	char buf[BUF_SIZE];
	int n = read(fd, buf, BUF_SIZE);
	if (n > 0) {
		mode_t mode = S_IWUSR | S_IRUSR;
		int new_fd = open(argv[2], O_RDWR | O_CREAT, mode);
		write(new_fd, buf, n);
		close(new_fd);
	}
	close(fd);
	return 0;
}

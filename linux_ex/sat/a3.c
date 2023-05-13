#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv)
{
	char *buf;
	buf = malloc(1<<31);
	strcpy(buf, "This is Test");
	printf("%s\n", buf);
	return 0;
}

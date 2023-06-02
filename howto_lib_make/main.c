/** main.c : main function **/

#include <stdio.h>

int func_1(char *);
int func_2(char *);

int main()
{
	(void)func_1("LIB 1 Function Call...");
	(void)func_2("LIB 2 Function Call...");

	return 0;
}

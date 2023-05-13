# include <stdio.h>
void main()
{
	int i;
	int num = 0;
	int j = 1;
	printf ("Enter the number: ");
	scanf ("%d", &num);
	for (i=1; i<num; i++)
		j=j*i;
	printf("The factorial of %d is %d\n", num, j);
}

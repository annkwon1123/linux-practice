#include <stdio.h>
int main()
{
	int iCount;
	int iDan;
	for(iDan = 1; iDan < 10; ++iDan)
	{
		for (iCount = 1; iCount < 10; ++iCount)
		{
			printf("%d * %d = %d\n", iDan, iCount, iDan * iCount);
		}
		printf("\n");
	}
}

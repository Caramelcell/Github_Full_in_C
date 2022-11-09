#include "main.h"

int printIntArr(const int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%-3d", arr[i]);
	}
	printf("\n");
	return 0;
}
#include "main.h"

int Question7()
{
	srand(time(NULL));
	int i, j, len;
	len = 10 + rand() % 10;
	int* arr = (int*)malloc(len * sizeof(int));
	for (i = 0; i < len; i++)
	{
		arr[i] = rand() % 100;
	}
	printIntArr(arr, len);
	i = 0, j = len - 1;
	while (i < j)
	{
		SWAP(arr[i], arr[j]);
		i++;
		j--;
	}
	printIntArr(arr, len);
	free(arr);
	return 0;
}
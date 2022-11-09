#include "main.h"

int Question12()
{
	int N, i, num, ret;
	srand(time(NULL));
	N = 10 + rand() % 10;
	int* arr = (int*)malloc((N + 1) * sizeof(int));
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % 100;
	}
	qsort(arr, N, sizeof(int), qsortCompare12);
	printIntArr(arr, N);
	ret = scanf("%d", &num);
	ERROR_CHECK(ret, -1, "scanf");
	ERROR_CHECK(ret, 0, "scanf");
	for (i = 0; i < N; i++)
	{
		if (arr[i] > num)
		{
			SWAP(arr[i], num);
		}
	}
	arr[N] = num;
	printIntArr(arr, N + 1);
	free(arr);
	return 0;
}
#include "sortfunc.h"

int main()
{
	int N = 10;	//数量
	int R = 100;	//范围
	int i;
	int* arr = (int)malloc(N * sizeof(int));
	srand(time(NULL));	//产生种子
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % R - R / 2;
	}
	print(arr, N);
	printf("\n------------------\n");

	//bubble(arr, N);	//ac
	//select(arr, N);	//ac
	//insert(arr, N);	//ac
	merge(arr, 0, N - 1);
	print(arr, N);
	check(arr, N);

	return 0;
}

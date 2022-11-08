#include "sortfunc.h"

int main()
{
	int N = 10000;	//数量
	int R = 1000000;	//范围
	int i;
	time_t start, end;
	int* arr = (int*)malloc(N * sizeof(int));
	srand(time(NULL));	//产生种子
	for (i = 0; i < N; i++)
	{
		arr[i] = rand() % R;
	}
	//print(arr, N);
	printf("\n------------------------------------\n");
	time(&start);

	//bubble(arr, N);	//ac
	//select(arr, N);	//ac
	//insert(arr, N);	//ac
	merge(arr, 0, N - 1);	//ac
	//quick(arr, 0, N - 1);	//ac
	//heap(arr, N);		//ac

	//print(arr, N);
	time(&end);
	printf("%lld\n", end - start);

	check(arr, N);

	return 0;
}

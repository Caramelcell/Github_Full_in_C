#include "main.h"

int Question28()
{
	int len, i, j, flag;
	len = 10;
	srand(time(NULL));
	int* arr = (int*)malloc(len * sizeof(int));
	for (i = 0; i < len; i++)
	{
		arr[i] = rand() % 100;
	}
	printIntArr(arr, len);
	for (i = len - 1; i > 0; i--)	//iʼ��ָ�����һ����������λ��
	{
		flag = 0;
		for (j = 0; j < i; j++)	//jʼ��ָ��ǰ���������ֵ
		{
			if (arr[j] > arr[j + 1])
			{
				SWAP(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (0 == flag)
		{
			break;
		}
	}
	printIntArr(arr, len);
	free(arr);
	return 0;
}
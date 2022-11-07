#include "sortfunc.h"

void print(const int* arr, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
}

int check(const int* arr, int len)
{
	int i;
	for (i = 0; i < len - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			printf("error\n");
			return -1;
		}
	}
	printf("accept\n");
	return 0;
}

void bubble(int* arr, int len)
{
	int i, j, flag;
	for (i = len - 1; i > 0; i--)	//i始终指向最后一个无序数的位置
	{
		flag = 0;
		for (j = 0; j < i ; j++)	//j始终指向当前遍历的最大值
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
}

void select(int* arr, int len)
{
	int i, j, min;
	for (i = 0; i < len - 1; i++)
	{
		min = arr[i];
		for (j = i + 1; j < len; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
			}
		}
		SWAP(arr[i], min);
	}
}

void insert(int* arr, int len)
{
	int i, j, insert_val;
	for (i = 1; i < len; i++)
	{
		insert_val = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (insert_val < arr[j])
			{
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}
		arr[j + 1] = insert_val;
	}
}

void order_merge(int* arr, int left, int mid, int right)
{
	int* newarr = (int*)malloc((right - left + 1) * sizeof(int));
	int i = left, j = mid + 1, k;
	for (k = 0; k < right - left + 1; k++)
	{
		newarr[k] = arr[k];
	}
	k = 0;
	while (i <= mid && j <= right)
	{
		if (newarr[i] < newarr[j])
		{
			arr[k++] = newarr[i++];
		}
		else {
			arr[k++] = newarr[j++];
		}
	}
	while (i > mid && j <= right)
	{
		arr[k++] = newarr[j++];
	}
	while (j > right && i <= mid)
	{
		arr[k++] = newarr[i++];
	}
	free(newarr);
}
void merge(int* arr, int left, int right)
{
	if (left < right)
	{
		int mid = left + ((right - left) >> 1);
		merge(arr, left, mid);
		merge(arr, mid + 1, right);
		order_merge(arr, left, mid, right);
	}
}
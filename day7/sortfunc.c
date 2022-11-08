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
			printf("\nerror\n");
			return -1;
		}
	}
	printf("\naccept\n");
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

void merge(int* arr, int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = left + ((right - left) >> 1);
		merge(arr, left, mid);
		merge(arr, mid + 1, right);

		int* newarr = (int*)malloc((right + 1) * sizeof(int));
		int i = left, j = mid + 1, k;
		for (k = 0; k <= right; k++)
		{
			newarr[k] = arr[k];
		}
		k = left;
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
}

void quick(int* arr, int left, int right)
{
	if (right <= left)
	{
		return;
	}
	//随机取数组一个数与最后一个数交换
	int r = left + rand() % (right - left + 1);
	SWAP(arr[right], arr[r]);
	//将最右边的数作为分割值
	int spilt = arr[right];
	int i, j;
	i = j = left;
	while (i < right)
	{
		if (arr[i] <= spilt)
		{
			SWAP(arr[i], arr[j]);
			j++;
		}
		i++;
	}
	SWAP(arr[j], arr[right]);
	quick(arr, left, j - 1);
	quick(arr, j, right);
}

void maxheap(int* arr, int len, int point)
{
	int dad, son;
	dad = point;
	son = (dad << 1) | 1;
	while (son < len)
	{
		if ((son + 1) < len && arr[son + 1] > arr[son])
		{
			son += 1;
		}
		if (arr[dad] < arr[son])
		{
			SWAP(arr[dad], arr[son]);
			dad = son;
			son = (dad << 1) | 1;
		}
		else {
			break;
		}
	}
}
void heap(int* arr, int len)
{
	int i;
	for (i = (len >> 1) - 1; i >= 0; i--)
	{
		maxheap(arr, len, i);
	}
	SWAP(arr[0], arr[len - 1]);
	for (i = len - 1; i > 0; i--)
	{
		maxheap(arr, i, 0);
		SWAP(arr[0], arr[i - 1]);
	}
}
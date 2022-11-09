#include "main.h"

static void itostr(int i, char* arr)
{
	int j;
	for (j = 0; i > 0; i /= 10)
	{
		arr[j++] = i % 10 + '0';
	}
	i = 0, j -= 1;
	while (i < j)
	{
		SWAP(arr[i], arr[j]);
		i++;
		j--;
	}
}
int Question20()
{
	int i;
	char arr[1000] = { 0 };
	scanf("%d", &i);
	itostr(i, arr);
	puts(arr);
	return 0;
}
#include "main.h"

int Question6()
{
	int n, i;
	int arr[3] = { 0 };
	while (scanf("%d", &n) != EOF)
	{
		for (i = 0; i <= n; i++)
		{
			if (0 == i || 1 == i)
			{
				arr[i] = 1;
			}
			else {
				arr[i % 3] = arr[(i + 1) % 3] + arr[(i + 2) % 3];
			}
		}
		printf("result is %d\n", arr[(i - 1) % 3]);
		rewind(stdin);
	}
	return 0;
}
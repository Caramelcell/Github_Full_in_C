#include "main.h"

int Question24()	//不会这题，看了一下Google的各种解法，OK还是不会，跳过...
{
	int i, j, m, n;
	int arr[8][8] = { 0 };
	arr[0][0] = 2;
	arr[0][1] = 2;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			if (0 == arr[i][j])
			{
				arr[i][j] = 1;
				for (m = 0; m < 8; m++)
				{
					for (n = 0; n < 8; n++)
					{
						if ((m - n == i - j) || (m + n == i + j) || m == i || n == j)
						{
							if (arr[m][n] == 0)
							{
								arr[m][n] = 2;
							}
						}
					}
				}
			}
		}
	}
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
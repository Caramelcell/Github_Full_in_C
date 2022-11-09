#include "main.h"

int Question18()
{
	int i, j;
	int matrix[5][5] = { 0 };
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (i <= j)
			{
				matrix[i][j] = 1;
			}
			else {
				matrix[i][j] = i - j + 1;
			}
			printf("%2d", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
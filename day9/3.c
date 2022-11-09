#include "main.h"

int Question3()
{
	int i, j, sum = 0;
	int matrix[3][3] = { 0 };
	srand(time(NULL));
	printf("the matrix is :\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			matrix[i][j] = rand() % 100;
			printf("%-3d", matrix[i][j]);
			if (i == j)
			{
				sum += matrix[i][j];
			}
		}
		printf("\n");
	}
	printf("the sum is %d\n", sum);
	return 0;
}
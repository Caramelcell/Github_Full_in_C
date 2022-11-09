#include "main.h"

int Question13()
{
	int i;
	for (i = 100; i <= 200; i++)
	{
		if ((2 == i % 3) && (3 == i % 5) && (2 == i % 7))
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}
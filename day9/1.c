#include "main.h"

int Question1()
{
	char arr[100] = { 0 };
	while (scanf("%s", arr) != EOF)
	{
		double x = atof(arr);
		double y;
		if (x < 5)
		{
			y = x;
		}
		else if (x >= 15)
		{
			y = x - 6;
		}
		else
		{
			y = x + 6;
		}
		printf("x=%.2lf,y=%.2lf\n", x, y);
	}
	return 0;
}
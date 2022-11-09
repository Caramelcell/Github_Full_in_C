#include "main.h"

int Question4()
{
	int i, single, ten, hundred, sum, num;
	num = 1000;
	for (i = num / 10; i < num; i++)
	{
		single = i % 10;
		ten = i / 10 % 10;
		hundred = i / 100;
		sum = single * single * single + ten * ten * ten + hundred * hundred * hundred;
		if (sum == i)
		{
			printf("%d\n", sum);
		}
	}
	return 0;
}
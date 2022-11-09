#include "main.h"

int Question11()
{
	int i, num, ret;
	ret = scanf("%d", &num);
	ERROR_CHECK(ret, -1, "scanf");
	i = 2;
	printf("%d = 1", num);
	while (1 != num)
	{
		if (0 == num % i)
		{
			printf("*%d", i);
			num /= i;
		}
		else {
			i++;
		}
	}
	printf("\n");
	return 0;
}
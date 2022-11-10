#include "main.h"

static int func(int n)
{
	if (n > 0)
	{
		return func(n - 1) + (1 << n);
	}
	else {
		return 0;
	}
}
int Question26()
{
	int n, sub, ret;
	double result;
	ret = scanf("%d", &n);
	ERROR_CHECK(ret, -1, "scanf");
	sub = 1 << (n + 1);
	if (n >= 30)
	{
		printf("sorry 0.0\n");
		return -1;
	}
	result = func(n) / (double)sub;
	printf("%.15lf\n", result);
	return 0;
}
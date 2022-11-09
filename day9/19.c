#include "main.h"

static int sum(int n)
{
	if (n > 0)
	{
		n = sum(n - 1) + n * 10 + 2;
		return n;
	}
	else if (0 == n)
	{
		return 0;
	}
}
int Question19()
{
	int result, ret;
	int n;
	ret = scanf("%d", &n);
	ERROR_CHECK(ret, -1, "scanf");
	ERROR_CHECK(ret, 0, "scanf");
	result = sum(n);
	printf("%d\n", result);
	return 0;
}
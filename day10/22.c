#include "main.h"

int Question22()
{
	int a, b;
	a = 56, b = 78;
	printf("%3d%3d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%3d%3d\n", a, b);
	return 0;
}
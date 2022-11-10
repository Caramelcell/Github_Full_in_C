#include "main.h"

int Question25()
{
	char a[40] = { "My name is Li jilin." };
	char b[40] = { "Mr. Zhang Haoling is very happy." };
	int i, j;
	i = 11, j = 4;
	while (j < 17)
	{
		a[i++] = b[j++];
	}
	puts(a);
	return 0;
}
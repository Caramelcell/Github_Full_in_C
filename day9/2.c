#include "main.h"

int Question2()
{
	char c;
	while ((c = getchar()) != EOF)
	{
		if (c >= 'a' && c <= 'z')
		{
			printf("transform result is %c\n", c - 32);
		}
		else if (c == '\n')
		{
			rewind(stdin);
		}
		else
		{
			printf("error input\n");
		}
	}
	return 0;
}
#include "main.h"

int Question29()
{
	int dig, sum, spilt1, spilt2, spilt3, spilt4;
	scanf("%d", &dig);
	sum = 0;
	spilt1 = dig >> 12;
	spilt2 = (dig >> 8) ^ (spilt1 << 4);
	spilt3 = (dig >> 4) ^ (spilt2 << 4) ^ (spilt1 << 8);
	spilt4 = dig ^ (spilt3 << 4) ^ (spilt2 << 8) ^ (spilt1 << 12);
	sum = spilt1 + spilt2 + spilt3 + spilt4;
	printf("%d\n", sum);
	return 0;
}
#include "main.h"

int Question5()
{
	double score;
	while (scanf("%lf", &score) != EOF)
	{
		if (score > 100 || score < 0)
		{
			printf("error score\n");
		}
		else if (score >= 90)
		{
			printf("A\n");
		}
		else if (score >= 80)
		{
			printf("B\n");
		}
		else if (score >= 70)
		{
			printf("C\n");
		}
		else if (score >= 60)
		{
			printf("D\n");
		}
		else if (score < 60)
		{
			printf("try again\n");
		}
		rewind(stdin);
	}
	return 0;
}
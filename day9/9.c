#include "main.h"

int Question9()
{
	double max, min, score, flag;
	max  = score = 0;
	flag = min = 1000;
	while (scanf("%lf", &score) != EOF)
	{
		if (flag == score)
		{
			getchar();
		}
		flag = score;
		if (score >= 0 && score <= 100)
		{
			max = max > score ? max : score;
			min = min < score ? min : score;
		}
		else if (score > 100)
		{
			//do nothing
		}
		else {
			break;
		}
	}
	if (max >= min)
	{
		printf("max score is %5.2lf,min score is %5.2lf\n", max, min);
	}
	else {
		printf("error\n");
	}
	return 0;
}
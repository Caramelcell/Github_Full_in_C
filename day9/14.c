#include "main.h"

int Question14()
{
	double score[10] = { 0 };
	double sum = 0;
	int i, ret, count1, count2;
	count1 = count2 = 0;
	for (i = 0; i < 10; i++)
	{
		ret = scanf("%lf", &score[i]);
		ERROR_CHECK(ret, -1, "scanf");
		if (score[i] > 80)
		{
			count1++;
		}
		else if (score[i] < 60)
		{
			count2++;
		}
		sum += score[i];
	}
	printf("80分以上有%d人，不及格有%d人，平均分为%5.2lf\n", count1, count2, sum / 10.0);
	return 0;
}
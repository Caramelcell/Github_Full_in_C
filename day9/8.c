#include "main.h"

int Question8()
{
	double a, b, c, p, area;
	int flag1, flag2;
	char str1[3][10] = { "锐角","直角","钝角" };
	char str2[3][10] = { "","等腰","等边" };
	printf("请输入三角形的边长：\n");
	scanf("%lf%lf%lf", &a, &b, &c);
	flag1 = flag2 = 0;
	if (a < b)
	{
		SWAP(a, b);
	}
	if (a < c)
	{
		SWAP(a, c);
	}
	if (b + c > a)
	{
		if (a == b && b == c)
		{
			flag2 = 2;
		}
		else if (a == b || b == c)
		{
			flag2 = 1;
		}
		if (c * c + b * b > a * a)
		{
			flag1 = 0;
		}
		else if (c * c + b * b < a * a)
		{
			flag1 = 2;
		}
		else {
			flag1 = 1;
		}
		p = (a + b + c) / 2.0;
		area = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("该三角形为%s%s三角形,面积近似为%5.2lf\n", str2[flag2], str1[flag1], area);
	}
	else {
		printf("无法组成三角形\n");
	}
	return 0;
}
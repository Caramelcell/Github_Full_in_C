#include "main.h"

int Question10()
{
	double C, F;
	int ret;
	printf("请输入华氏温度：\n");
	ret = scanf("%lf", &F);
	ERROR_CHECK(ret, -1, "scanf");
	C = (F - 32) * 5 / 9.0;
	printf("该华氏温度转换的摄氏温度为：%5.2lf\n", C);
	return 0;
}
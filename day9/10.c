#include "main.h"

int Question10()
{
	double C, F;
	int ret;
	printf("�����뻪���¶ȣ�\n");
	ret = scanf("%lf", &F);
	ERROR_CHECK(ret, -1, "scanf");
	C = (F - 32) * 5 / 9.0;
	printf("�û����¶�ת���������¶�Ϊ��%5.2lf\n", C);
	return 0;
}
#include "main.h"

#define PI 3.1415
int Question16()
{
	double h, r, bottomArea, volume;
	int ret;
	ret = scanf("%lf%lf", &r, &h);
	ERROR_CHECK(ret, -1, "scanf");
	ERROR_CHECK(ret, 0, "scanf");
	bottomArea = PI * r * r;
	volume = bottomArea * h;
	printf("Բ��������Ϊ%.2lf�����Ϊ%.2lf\n", bottomArea, volume);
	return 0;
}
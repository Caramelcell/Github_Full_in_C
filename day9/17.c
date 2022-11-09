#include "main.h"

int Question17()
{
	char arr[100] = { 0 };
	int alp, space, dig, other, i, ret;
	alp = space = dig = other = 0;
	for (i = 0; i < 100; i++)
	{
		ret = scanf("%c", &arr[i]);
		ERROR_CHECK(ret, -1, "scanf");
		if (arr[i] == '\n')
		{
			break;
		}
		if ((arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] >= 'A' && arr[i] <= 'Z'))
		{
			alp++;
		}
		else if (arr[i] == ' ')
		{
			space++;
		}
		else if (arr[i] >= '0' && arr[i] <= '9')
		{
			dig++;
		}
		else {
			other++;
		}
	}
	printf("英文字母个数为：%d，空格个数为：%d，数字个数为：%d，其他字符个数为：%d\n", alp, space, dig, other);
	return 0;
}
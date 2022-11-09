#include "main.h"

int Question15()
{
	char c;
	lable:
	c = getchar();
	if (c == '\n')
	{
		goto lable;
	}
	else {
		if (c >= 'a' && c <= 'z')
		{
			printf("输入的是小写字母\n");
			return 0;
		}
		else if (c >= 'A' && c <= 'Z') 
		{
			printf("输入的是大写字母\n");
			return 0;
		}
		else {
			printf("输入的字符不是26个英文字母中的任何一个\n");
			return -1;
		}
	}
}
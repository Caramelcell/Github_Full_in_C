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
			printf("�������Сд��ĸ\n");
			return 0;
		}
		else if (c >= 'A' && c <= 'Z') 
		{
			printf("������Ǵ�д��ĸ\n");
			return 0;
		}
		else {
			printf("������ַ�����26��Ӣ����ĸ�е��κ�һ��\n");
			return -1;
		}
	}
}
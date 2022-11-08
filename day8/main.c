#include <stdio.h>

int main()
{
	int n = -1;
	int count = 0, temp = n;
	//求n的2进制中有几个1
	//算法1
	while (temp)
	{
		temp = temp & (temp - 1);
		count++;
	}
	printf("%d\n", count);

	temp = n;
	//SWAR算法
	temp = (temp & 0x55555555) + ((temp >> 1) & 0x55555555);	//2个位一组，1个位作为一个数，两两相加，高位补0
	temp = (temp & 0x33333333) + ((temp >> 2) & 0x33333333);	//4个位一组，2个位作为一个数，两两相加，高位补0
	temp = (temp & 0x0F0F0F0F) + ((temp >> 4) & 0x0F0F0F0F);	//8个位一组，4个位作为一个数，两两相加，高位补0
	temp = (temp * 0x01010101) >> 24;				//上次运算得到如下结果 0000 (0101) 0000 (0101) 0000 (0101) 0000 (0100)括号内相加得到 1 0011，转换成十进制就是原数的二进制中1的个数
	printf("%d\n", temp);
}

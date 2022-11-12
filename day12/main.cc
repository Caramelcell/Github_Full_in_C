#include <iostream>
#include "String.h"

int main()
{
	//unsigned int a, b, d, sum;
	//int result[31] = { 0 };
	//int  i = 0;
	//std::cin >> a >> b >> d;
	//sum = a + b;
	//do
	//{
	//	result[i++] = sum % d;
	//	sum /= d;
	//} while (sum);
	//for (; i > 0; i--)
	//{
	//	std::cout << result[i - 1];
	//}

//	const char* p = "srt";
//	const char*& rhs = p;
	String s1;
	const String s2("hello");
	const String& rhs = s2;
	String s3(rhs);

	return 0;
}
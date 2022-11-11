#include <iostream>
#include <string>

int main()
{
	//int a, b;
	//std::cin >> a >> b;
	//std::cout << a << " " << b << std::endl;
	std::string str[10];
	//while (std::cin >> str[0])
	//{
	//	int len = str[0].length();
	//}

	//for (int i = 0; std::cin >> str[i]; i++)
	//{
	//	int len = str[i].length();
	//	int j = 0;
	//	while (j < len - j - 1)
	//	{
	//		char temp = str[i][j];
	//		str[i][j] = str[i][len - j - 1];
	//		str[i][len - j - 1] = temp;
	//		j++;
	//	}
	//}	//·­×ªµ¥´Ê
	int i, j, count;
	i = count = 0;
	while (std::cin >> str[i++])
	{
		count++;
	}
	for (j = count; j > 0; j--)
	{
		std::cout << str[j - 1];
		if (j - 1)
		{
			std::cout << " ";
		}
		//else {
		//	std::cout << std::endl;
		//}
	}
	return 0;
}
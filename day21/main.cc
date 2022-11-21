#include <string.h>

#include "my_string.h"

int main() {
  String s1;
  String s2("hello world");
  std::cout << s1.size() << std::endl;
  std::cout << s2.size() << std::endl;

  char c[20] = {0};
  strcpy(c, s2.c_str());

  s1 = "hi";
  std::cout << (int)(s1 == s2) << std::endl;
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  std::cin >> s1 >> s2;
  std::cout << s1 << std::endl;
  std::cout << s2 << std::endl;

  String s3;
  s3 = s1 + s2;
  String s4 = s1 + "world";
  String s5 = "hello" + s2;
  std::cout << s3 << std::endl;
  std::cout << s4 << std::endl;
  std::cout << s5 << std::endl;

  return 0;
}
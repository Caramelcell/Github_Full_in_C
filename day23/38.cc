#include "main.h"

namespace {
int Add(int num1, int num2) {
  std::cout << "整数之和：";
  return num1 + num2;
}
double Add(double num1, double num2) {
  std::cout << "浮点数之和：";
  return num1 + num2;
}
}  // namespace

int Question38() {
  int num1 = 1, num2 = 2;
  double num3 = 1.1, num4 = 2.2;
  std::cout << Add(num1, num2) << std::endl << Add(num3, num4) << std::endl;
  return 0;
}
#include "main.h"

namespace {
using std::cout;
using std::endl;
using std::vector;
void print(const vector<int>& num) {
  for (auto i : num) {
    cout << i << " ";
  }
  cout << endl;
}
}  // namespace

int Question50() {
  using std::vector;
  // num1为空
  vector<int> num1;
  print(num1);
  // num2是12345
  vector<int> num2{1, 2, 3, 4, 5};
  print(num2);
  // num3是num2的第一个元素到最后一个元素的拷贝，具体看迭代器位置
  vector<int> num3(num2.begin(), num2.end());
  print(num3);
  // num4是3个0(int默认初始化为0)
  vector<int> num4(3);
  print(num4);
  // num5是10个3
  vector<int> num5(10, 3);
  print(num5);
  // num6是num5的拷贝(深拷贝)
  vector<int> num6(num5);
  print(num6);
  return 0;
}
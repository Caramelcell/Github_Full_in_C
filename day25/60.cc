#include "main.h"

namespace {
using std::cout;
using std::endl;
using std::vector;

void BubbleSort(vector<int>& num) {
  for (auto i = num.end() - 1; i != num.begin(); --i) {
    for (auto j = num.begin(); j != i; ++j) {
      if (*j > *(j + 1)) {
        Swap(*j, *(j + 1));
      }
    }
  }
}
}  // namespace
int Question60() {
  vector<int> num;
  srand(time(NULL));
  for (int i = 0; i < 10; ++i) {
    num.push_back(rand() % 100);
  }
  PrintContainer(num);
  BubbleSort(num);
  PrintContainer(num);
  return 0;
}
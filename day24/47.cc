#include "main.h"

namespace {
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void Print(const vector<int>& num) {
  for (auto i : num) {
    cout << i << " ";
  }
  cout << endl;
}
}  // namespace

int Question47() {
  vector<int> num(10, 6);
  Print(num);
  for (auto i = num.begin(); i != num.end(); ++i) {
    *i *= 2;
  }
  Print(num);
  return 0;
}
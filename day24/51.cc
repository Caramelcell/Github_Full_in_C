#include "main.h"

namespace {
using std::cout;
using std::endl;
using std::list;
using std::vector;

template <typename T>
void Print(const T& t) {
  for (auto i : t) {
    cout << i << " ";
  }
  cout << endl;
}
}  // namespace
int Question51() {
  list<int> l1{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Print<list<int>>(l1);
  vector<double> v1(l1.begin(), l1.end());
  Print<vector<double>>(v1);
  vector<int> v2(l1.begin(), l1.end());
  Print<vector<int>>(v2);
  vector<double> v3(v2.begin(), v2.end());
  Print<vector<double>>(v3);
  return 0;
}
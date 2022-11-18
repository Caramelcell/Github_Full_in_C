#include "main.h"

using std::cin;
using std::cout;
using std::endl;
using std::vector;

void PrintAdjacentSum() {
  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.push_back(num);
  }
  auto size = nums.size();
  for (decltype(size) i = 0; i < size; i += 2) {
    if (i == size - 1) {
      cout << nums.at(i) << endl;
    } else {
      cout << nums.at(i) + nums.at(i + 1) << endl;
    }
  }
}

void PrintSum() {
  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.push_back(num);
  }
  // auto size = nums.size();
  // for (decltype(size) i = 0; i < size; ++i) {
  //   if (i < size - i - 1) {
  //     cout << nums.at(i) + nums.at(size - i - 1) << endl;
  //   } else if (i == size - i - 1) {
  //     cout << nums.at(i) << endl;
  //   }
  // }
  auto first = nums.begin();
  auto end = nums.end() - 1;
  while (first < end) {
    cout << *first + *end << endl;
    ++first;
    --end;
  }
  if (first == end) {
    cout << *first << endl;
  }
}
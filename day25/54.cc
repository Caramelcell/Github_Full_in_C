#include "main.h"

int Question54() {
  using std::cout;
  using std::deque;
  using std::endl;
  using std::list;

  list<int> l1;
  srand(time(NULL));
  for (int i = 0; i < 20; ++i) {
    l1.push_back(rand() % 100);
  }
  PrintContainer(l1);
  deque<int> odd, even;
  for (auto i = l1.begin(); i != l1.end(); ++i) {
    if (0 == *i % 2) {
      even.push_back(*i);
    } else {
      odd.push_back(*i);
    }
  }
  PrintContainer(odd);
  PrintContainer(even);
  return 0;
}
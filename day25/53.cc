#include "main.h"

int Question53() {
  using std::cin;
  using std::cout;
  using std::deque;
  using std::endl;
  using std::string;

  string buf;
  deque<string> d1;
  while (cin >> buf) {
    d1.push_back(buf);
  }
  for (deque<string>::iterator i = d1.begin(); i != d1.end(); ++i) {
    cout << *i << endl;
  }  // PrintContainer(d1);
  return 0;
}
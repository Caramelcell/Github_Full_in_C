#include "main.h"

int Question45() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;

  string str;
  string buf;
  string space(" ");
  while (cin >> buf) {
    if (!str.empty()) {
      str += space;
    }
    str += buf;
  }
  cout << str << endl;
  return 0;
}
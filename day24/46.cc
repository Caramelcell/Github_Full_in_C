#include "main.h"

int Question46() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;

  string str;
  cin >> str;
  cout << str << endl;
  for (auto i = str.begin(); i != str.end(); ++i) {
    if (ispunct(*i)) {
      *i = ' ';
    }
  }
  cout << str << endl;
  return 0;
}
#include "main.h"

int Question55() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;
  using std::vector;

  char c;
  vector<char> buf;
  while (cin >> c) {
    buf.push_back(c);
  }
  PrintContainer(buf);
  string str(buf.begin(), buf.end());
  cout << str << endl;
  return 0;
}
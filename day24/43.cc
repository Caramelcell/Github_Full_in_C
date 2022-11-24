#include "main.h"

int Question43() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;

  cout << "一次一行：" << endl;
  string str;
  while (getline(cin, str)) {
    if (str.empty()) {
      break;
    }
    cout << str << endl;
  }
  cout << "一次一词：" << endl;
  string word[100];
  int i = 0;
  while (cin >> word[i++]) {
    cout << word[i - 1] << endl;
  }
  return 0;
}
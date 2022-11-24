#include "main.h"

namespace {
using std::cin;
using std::cout;
using std::endl;
using std::string;

int StrCompare(const string& str1, const string& str2) {
  auto i = str1.begin(), j = str2.begin();
  for (; i != str1.end() && j != str2.end(); ++i, ++j) {
    if (*i != *j) {
      return *i - *j;
    }
  }
  if (str1.size() == str2.size()) {
    return 0;
  } else {
    return str1.size() - str2.size();
  }
}
void PrintResult(const int result) {
  cout << "str1 ";
  if (result > 0) {
    cout << ">";
  } else if (result < 0) {
    cout << "<";
  } else {
    cout << "=";
  }
  cout << " str2" << endl;
}
}  // namespace
int Question48() {
  string str1, str2;
  cin >> str1 >> str2;
  cout << str1 << " " << str2 << endl;
  PrintResult(StrCompare(str1, str2));

  char c_str1[100] = {0};
  char c_str2[100] = {0};
  strcpy(c_str1, str1.c_str());
  strcpy(c_str2, str2.c_str());
  cout << c_str1 << " " << c_str2 << endl;
  PrintResult(strcmp(c_str1, c_str2));
  return 0;
}
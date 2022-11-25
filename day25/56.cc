#include "main.h"

int Question56() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::string;

  string name, perfix, suffix;
  cin >> name >> perfix >> suffix;
  string full_name(name);
  string::iterator i = full_name.begin();
  for (auto j = perfix.rbegin(); j != perfix.rend(); ++j) {
    full_name.insert(i, *j);
  }
  for (auto k = suffix.begin(); k != suffix.end(); ++k) {
    full_name.insert(full_name.end(), *k);
  }
  cout << full_name << endl << name << endl << perfix << endl << suffix << endl;
  return 0;
}
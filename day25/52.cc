#include "main.h"

int Question52() {
  using std::cout;
  using std::endl;
  using std::list;
  using std::string;
  using std::vector;

  char cstr[12] = "hello world";
  list<char*> l1;
  l1.push_back(cstr);
  vector<string> v1{cstr};
  v1.push_back(*l1.begin());
  PrintContainer(l1);
  PrintContainer(v1);
  return 0;
}
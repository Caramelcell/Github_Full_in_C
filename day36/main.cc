#include <iostream>
#include <string>
#include <vector>

#include "my_string.h"

class Axcess {
 public:
  Axcess() { cout << "default constructor" << endl; }
  Axcess(const int num, const String& str) : num_(num), str_(str) {
    cout << "constructor" << endl;
  }
  Axcess(const Axcess& other) : num_(other.num_), str_(other.str_) {
    cout << "copy constructor" << endl;
  }
  ~Axcess() { cout << "destructor" << endl; }
  Axcess& operator=(const Axcess& rhs) {
    if (this != &rhs) {
      str_ = rhs.str_;
      num_ = rhs.num_;
      cout << "assignment operator" << endl;
    }
    return *this;
  }
  // move constructor
  Axcess(Axcess&& other) : num_(move(other.num_)), str_(move(other.str_)) {
    cout << "move constructor" << endl;
    other.str_ = nullptr;
  }
  Axcess& operator=(Axcess&& rhs) {
    if (this != &rhs) {
      str_ = move(rhs.str_);
      num_ = move(rhs.num_);
      rhs.str_ = nullptr;
      cout << "move assignment operator" << endl;
    }
    return *this;
  }

 private:
  int num_;
  String str_;
};

int main() {
  String str1("1ello");
  String str2("2ello");
  Axcess obj1 = Axcess(1, str1);
  Axcess obj2;
  obj2 = Axcess(2, str2);
}
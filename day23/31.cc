#include "main.h"

namespace {
class String {
 public:
  String(char* Head) : head_{0} { strcpy(head_, Head); }
  ~String() {}

  void reverse() {
    int i = 0;
    int j = strlen(head_) - 1;
    while (i < j) {
      swap(head_[i++], head_[j--]);
    }
  }

  void print() { std::cout << head_ << std::endl; }

 private:
  char head_[100];
};
}  // namespace

int Question31() {
  char Head[6] = "hello";
  String str(Head);
  str.print();
  str.reverse();
  str.print();
  return 0;
}

#include "main.h"

namespace {
class Counter {
 public:
  Counter() : value_(0) {}
  Counter(int value) : value_(value) {}

  int ShowValue() { return value_; }

  Counter& operator++() {
    ++value_;
    return *this;
  }
  Counter operator++(int) {
    Counter temp(this->value_);
    ++value_;
    return temp;
  }
  Counter& operator--() {
    --value_;
    return *this;
  }
  Counter operator--(int) {
    Counter temp(this->value_);
    --value_;
    return temp;
  }

 private:
  int value_;
};
}  // namespace

int Question40() {
  Counter counter(10);
  std::cout << counter.ShowValue() << std::endl
            << (counter++).ShowValue() << std::endl
            << counter.ShowValue() << std::endl
            << (++counter).ShowValue() << std::endl
            << (counter--).ShowValue() << std::endl
            << counter.ShowValue() << std::endl
            << (--counter).ShowValue() << std::endl;
  return 0;
}
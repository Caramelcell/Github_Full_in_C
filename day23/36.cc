#include "main.h"

namespace {
class Time {
 public:
  Time() : minute_(0), sec_(0) {}
  Time(int minute, int sec) : minute_(minute), sec_(sec) {}

  void Print() { std::cout << minute_ << ":" << sec_ << std::endl; }

  Time& operator++() {
    ++sec_;
    if (60 == sec_) {
      sec_ = 0;
      ++minute_ %= 60;
    }
    return *this;
  }
  Time operator++(int) {
    Time temp(this->minute_, this->sec_);
    ++sec_;
    if (60 == sec_) {
      sec_ = 0;
      ++minute_ %= 60;
    }
    return temp;
  }

 private:
  int minute_;
  int sec_;
};
}  // namespace

int Question36() {
  Time t1(59, 58);
  std::cout << "初始值：";
  t1.Print();
  ++t1;
  std::cout << "前置++后：";
  t1.Print();
  Time t2 = t1++;
  std::cout << "后置++表达式返回值：";
  t2.Print();
  std::cout << "后置++后：";
  t1.Print();
  return 0;
}
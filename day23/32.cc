#include "main.h"

namespace {
class Box {
 public:
  Box() : len_(0), high_(0), wide_(0) {}

  void SetBox(double len, double high, double wide) {
    len_ = len;
    high_ = high;
    wide_ = wide;
  }

  double Volume() { return len_ * high_ * wide_; }
  double SurfaceArea() {
    return len_ * high_ * 2 + high_ * wide_ * 2 + len_ * wide_ * 2;
  }

 private:
  double len_;
  double high_;
  double wide_;
};
}  // namespace

int Question32() {
  Box box1;
  box1.SetBox(1.1, 1.1, 1.1);
  std::cout << box1.SurfaceArea() << std::endl << box1.Volume() << std::endl;
  return 0;
}
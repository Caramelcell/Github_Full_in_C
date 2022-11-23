#include "main.h"

namespace {
class Triangle {
  friend double operator+(Triangle& t1, Triangle& t2);

 public:
  Triangle() : side_a_(0), side_b_(0), side_c_(0) {}

  int SetTriangle(double side_a, double side_b, double side_c) {
    if (side_a + side_b > side_c || side_a + side_c > side_b ||
        side_b + side_c > side_a) {
      side_a_ = side_a;
      side_b_ = side_b;
      side_c_ = side_c;
      return 0;
    } else {
      std::cout << "非法边长" << std::endl;
      return -1;
    }
  }

  double Area() {
    double temp = (side_a_ + side_b_ + side_c_) / 2;
    return sqrt(temp * (temp - side_a_) * (temp - side_b_) * (temp - side_c_));
  }

 private:
  double side_a_;
  double side_b_;
  double side_c_;
};
double operator+(Triangle& t1, Triangle& t2) { return t1.Area() + t2.Area(); }
}  // namespace

int Question37() {
  Triangle t1;
  Triangle t2;
  t1.SetTriangle(1, 1, 1);
  t2.SetTriangle(3, 4, 5);
  std::cout << t1 + t2 << std::endl;
  return 0;
}
#include "main.h"

namespace {
const double PI = 3.14;

class Base {
 public:
  virtual double CalculateArea() = 0;
};
class Triangle : public Base {
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

  virtual double CalculateArea() {
    double temp = (side_a_ + side_b_ + side_c_) / 2;
    return sqrt(temp * (temp - side_a_) * (temp - side_b_) * (temp - side_c_));
  }

 private:
  double side_a_;
  double side_b_;
  double side_c_;
};
class Square : public Base {
 public:
  Square(double side) : side_(side) {}

  virtual double CalculateArea() { return side_ * side_; }

 private:
  double side_;
};
class Circle : public Base {
 public:
  Circle(double radius) : radius_(radius) {}

  virtual double CalculateArea() { return PI * radius_ * radius_; }

 private:
  double radius_;
};
}  // namespace

int Question42() {
  Triangle t1;
  t1.SetTriangle(3, 4, 5);
  std::cout << "三角形面积为：" << t1.CalculateArea() << std::endl;
  Square s1(2.2);
  std::cout << "正方形面积为：" << s1.CalculateArea() << std::endl;
  Base* c1 = new Circle(1.0);
  std::cout << "圆形面积为：" << c1->CalculateArea() << std::endl;
  return 0;
}
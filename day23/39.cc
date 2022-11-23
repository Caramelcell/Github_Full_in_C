#include "main.h"

namespace {
const double PI = 3.14;

class Shape {
 public:
  virtual double CalculateArea() = 0;
};
class Rectangle : public Shape {
 public:
  Rectangle(double len, double wide) : len_(len), wide_(wide) {}

  virtual double CalculateArea() { return len_ * wide_; }

 private:
  double len_;
  double wide_;
};
class Trapezoid : public Shape {
 public:
  Trapezoid(double top_side, double high, double bottom_side)
      : top_side_(top_side), high_(high), bottom_side_(bottom_side) {}

  virtual double CalculateArea() {
    return (top_side_ + bottom_side_) * high_ / 2;
  }

 private:
  double top_side_;
  double high_;
  double bottom_side_;
};
class Circle : public Shape {
 public:
  Circle(double radius) : radius_(radius) {}

  virtual double CalculateArea() { return PI * radius_ * radius_; }

 private:
  double radius_;
};
}  // namespace

int Question39() {
  Shape* r1 = new Rectangle(2.0, 3.0);
  std::cout << "长方形面积为：" << r1->CalculateArea() << std::endl;
  Shape* t1 = new Trapezoid(2.0, 2.0, 3.0);
  std::cout << "梯形面积为：" << t1->CalculateArea() << std::endl;
  Shape* c1 = new Circle(1.0);
  std::cout << "圆形面积为：" << c1->CalculateArea() << std::endl;
  return 0;
}
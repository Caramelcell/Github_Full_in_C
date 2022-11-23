#include "main.h"

namespace {
class ComplexNumber {
  friend ComplexNumber operator+(const ComplexNumber& num1,
                                 const ComplexNumber& num2);

 public:
  ComplexNumber() : real_(0), imaginary_(0) {}
  ComplexNumber(double real, double imaginary)
      : real_(real), imaginary_(imaginary) {}

  void Print() {
    std::cout << real_;
    if (imaginary_ < 0) {
      std::cout << imaginary_ << "i";
    } else if (imaginary_ > 0) {
      std::cout << "+" << imaginary_ << "i";
    }
    std::cout << std::endl;
  }

 private:
  double real_;
  double imaginary_;
};
ComplexNumber operator+(const ComplexNumber& num1, const ComplexNumber& num2) {
  ComplexNumber result;
  result.real_ = num1.real_ + num2.real_;
  result.imaginary_ = num1.imaginary_ + num2.imaginary_;
  return result;
}
}  // namespace

int Question35() {
  ComplexNumber num1(1, 0);
  num1.Print();
  ComplexNumber num2(2, -2);
  num2.Print();
  ComplexNumber num3 = num1 + num2;
  num3.Print();
  return 0;
}
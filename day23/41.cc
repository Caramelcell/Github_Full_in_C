#include "main.h"

namespace {
class Mammal {
 public:
  virtual void Speak() { std::cout << "Mammal talking" << std::endl; }
};
class Dog : public Mammal {
 public:
  void Speak() { std::cout << "Dog talking" << std::endl; }
};
}  // namespace

int Question41() {
  Dog single_dog;
  single_dog.Speak();
  return 0;
}
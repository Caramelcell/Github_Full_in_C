#include "main.h"

namespace {
class Tree {
 public:
  Tree(int ages = 0) : ages_(ages) {}

  void Grow(int years) { ages_ += years; }
  int ShowAge() { return ages_; }

 private:
  int ages_;
};
}  // namespace

int Question33() {
  Tree t1;
  t1.ShowAge();
  std::cout << t1.ShowAge() << std::endl;
  t1.Grow(20);
  std::cout << t1.ShowAge() << std::endl;
  return 0;
}
#include "stack_class.h"

#include <iostream>

//初始化顺序初始化列表顺序无关，只跟声明时的顺序有关，故仍然是top先初始化然后再bottom
EasyStack::EasyStack() : pbottom_(new int[10]), ptop_(nullptr) {}

EasyStack::~EasyStack() {
  delete[] pbottom_;
  pbottom_ = nullptr;
  ptop_ = nullptr;
}

int EasyStack::Push(int num) {
  if (!Full()) {
    if (Empty()) {
      ptop_ = pbottom_;
      *ptop_ = num;
    } else {
      *(++ptop_) = num;
    }
    return 0;
  } else {
    std::cout << "stack is full" << std::endl;
    return -1;
  }
}

int EasyStack::Pop() {
  if (!Empty()) {
    if (ptop_ == pbottom_) {
      ptop_ = nullptr;
      return *pbottom_;
    } else {
      return *(ptop_--);
    }
  } else {
    std::cout << "stack is empty" << std::endl;
    return -1;
  }
}

int EasyStack::Top() {
  if (!Empty()) {
    return *ptop_;
  } else {
    std::cout << "stack is empty" << std::endl;
    return -1;
  }
}

bool EasyStack::Empty() {
  if (nullptr == ptop_) {
    return true;
  } else {
    return false;
  }
}

bool EasyStack::Full() {
  if (ptop_ == (pbottom_ + 9)) {
    return true;
  } else {
    return false;
  }
}
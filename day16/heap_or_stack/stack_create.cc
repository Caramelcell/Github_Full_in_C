#include "stack_create.h"

StackCreate::StackCreate(int index, const char* data)
    : index_(index), data_(new char[strlen(data) + 1]) {
  std::cout << "StackCreate" << std::endl;
  strcpy(data_, data);
}
StackCreate::~StackCreate() {
  std::cout << "~StackCreate" << std::endl;
  delete[] data_;
}

void* StackCreate::operator new(size_t size) {
  std::cout << "operator new" << std::endl;
  void* ret = malloc(size);
  return ret;
}
void StackCreate::operator delete(void* ret) {
  std::cout << "operator delete" << std::endl;
  free(ret);
}
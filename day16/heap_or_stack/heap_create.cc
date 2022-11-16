#include "heap_create.h"

void HeapCreate::Destory(HeapCreate* phe) {
  std::cout << "Destory" << std::endl;
  delete phe;
}
HeapCreate::HeapCreate(int index, const char* data)
    : index_(index), data_(new char[strlen(data) + 1]) {
  std::cout << "HeapCreate" << std::endl;
}
HeapCreate::~HeapCreate() {
  std::cout << "~HeapCreate" << std::endl;
  delete[] data_;
  data_ = nullptr;
}
void* HeapCreate::operator new(size_t size) {
  std::cout << "operator new" << std::endl;
  void* ret = malloc(size);
  return ret;
}
void HeapCreate::operator delete(void* ret) {
  std::cout << "operator delete" << std::endl;
  free(ret);
}
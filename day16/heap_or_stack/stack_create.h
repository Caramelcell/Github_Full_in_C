#include <stdlib.h>
#include <string.h>

#include <iostream>

class StackCreate {
 public:
  StackCreate(int, const char*);
  ~StackCreate();

 private:
  void* operator new(size_t size);
  void operator delete(void*);

 private:
  int index_;
  char* data_;
};
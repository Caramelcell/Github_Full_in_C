#include <stdlib.h>
#include <string.h>

#include <iostream>

class HeapCreate {
 public:
  HeapCreate(int, const char*);

  void* operator new(size_t size);
  void operator delete(void*);

  static void Destory(HeapCreate*);

 private:
  ~HeapCreate();

  int index_;
  char* data_;
};
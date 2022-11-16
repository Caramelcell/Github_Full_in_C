#include "heap_create.h"
#include "stack_create.h"

int main() {
  // StackCreate* pst = new StackCreate(100, "stack");
  // delete pst;
  // new的时候发现operator被private了，无法调用，也就无法生成堆对象
  { StackCreate pst(1, "stack"); }
  // pst直接调用析构函数，不需要经过operator new，就直接生成了栈对象
  HeapCreate* phe = new HeapCreate(2, "heap");
  // new--->operator new--->构造函数--->堆对象
  // delete phe;
  // delete时发现析构函数被private了，无法调用进行销毁，就只能通过该类提供的Destory函数来进行销毁
  HeapCreate::Destory(phe);
  // HeapCreate phe(2, "heap");
  // phe在生成时直接调用构造函数，是栈对象，而栈对象是由编译器来决定释放内存销毁对象的时机的，因此当编译器检测到该对象的析构函数被
  // private时就不会创建对象而是报错，因为编译器无法去调用这个析构函数，即要生成栈对象一定要保证析构函数和构造函数都能被调用
  return 0;
}
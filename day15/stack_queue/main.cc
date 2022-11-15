#include <iostream>

#include "queue_class.h"
#include "stack_class.h"

int main() {
  EasyStack s1;
  for (int i = 0; i < 12; i++) {
    s1.Push(i + 1);
    std::cout << s1.Top() << std::endl;
  }
  for (int i = 0; i < 12; i++) {
    s1.Pop();
    std::cout << s1.Top() << std::endl;
  }

  CirclarQueue q1;
  for (int i = 0; i < 12; i++) {
    q1.Enqueue(i + 1);
    std::cout << q1.Front() << std::endl;
    std::cout << q1.Rear() << std::endl;
  }
  for (int i = 0; i < 5; i++) {
    q1.Dequeue();
    std::cout << q1.Front() << std::endl;
    std::cout << q1.Rear() << std::endl;
  }
  for (int i = 0; i < 12; i++) {
    q1.Enqueue(i + 10);
    std::cout << q1.Front() << std::endl;
    std::cout << q1.Rear() << std::endl;
  }
}
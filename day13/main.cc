#include <iostream>
#include "String.h"

int main()
{
  String s1;
  s1.print();

  String s2("Hello");
  s2.print();
  String s3 = "hi";
  s3.print();

  {
    String s4 = s2;
    s4.print();
  }//大括号结束意味着s4这个对象的生命周期结束了，自动调用析构函数回收了空间

  String& rhs = s3;
  String s5(rhs);
  s5.print();

  s3 = s2;
  s3.print();

  //String s6 = s2 + s3;

  return 0;
}

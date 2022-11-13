#include "String.h"
#include <string.h>
#include <iostream>

int String::allStringLen_ = 0;
//static修饰的静态成员，由于静态成员放在全局区内，因此不会成为某个对象的一部分，而是这个类的所有对象所共有的，且初始化是在类外进行的

String::String():pstr_(nullptr), len_(0)  //列表初始化，圆括号大括号之间的为列表，初始化是在这里初始化的
{}  //大括号内为赋值，因此const修饰的成员必须在圆括号与大括号之间初始化，而不能在大括号里面赋值

String::String(const char* pstr)
{
  int len = 0;
  const char* temp = pstr;
  while (temp && *temp)
  {
    len++;
    temp++;
  }
  pstr_ = new char[len + 1];
  allStringLen_ += len;
  len_ = len;
  for (int i = 0; i < len; i++)
  {
    pstr_[i] = pstr[i];
  }
  pstr_[len] = '\0';
}

//String::String() :String(nullptr) {}  //C11新特性

String::String(const String& rhs)
{
  pstr_ = new char[rhs.len_ + 1];
  allStringLen_ += rhs.len_;
  len_ = rhs.len_;
  for (int i = 0; i < rhs.len_; i++)
  {
    pstr_[i] = rhs.pstr_[i];
  }
  pstr_[len_] = '\0';
}

String& String::operator= (const String& rhs)
{
  // if(!rhs.pstr_)
  // {
  //   std::cout << "右值错误" << std::endl;
  //   return *this;
  // }  //不确定是否有必要，因为直接产生了段错误

  if(this != &rhs)  //防止右值为空或者左值自复制导致左值的原来空间被释放掉，此时就直接归零了
  {
    delete[] pstr_; //释放左值的原来空间
    pstr_ = new char[rhs.len_+1]; //深拷贝
    allStringLen_ = allStringLen_ - len_ + rhs.len_;
    len_ = rhs.len_;
    strcpy(pstr_,rhs.pstr_);
  }
  return *this;
}

String:: ~String()
{
  allStringLen_ -= len_;
  len_ = 0;
  delete[] pstr_;
  pstr_ = nullptr;
}

void String::print()
{
  for(int i = 0; i < len_; i++)
  {
    std::cout << pstr_[i];
  }
  std::cout << std::endl;
  std::cout << "current string lenth = " << len_ << std::endl;
  std::cout << "all string lenth = " << allStringLen_ << std::endl;
}
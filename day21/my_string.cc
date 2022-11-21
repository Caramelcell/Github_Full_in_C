#include "my_string.h"

#include <string.h>

String::String() : pstr_(nullptr) {}
String::String(const char* str) : pstr_(new char[strlen(str) + 1]) {
  strcpy(pstr_, str);
}
String::String(const String& str) : pstr_(new char[str.size()]) {
  strcpy(pstr_, str.pstr_);
}
String::~String() {
  delete pstr_;
  pstr_ = nullptr;
}

String& String::operator=(const char* str) {
  delete pstr_;
  pstr_ = new char[strlen(str) + 1];
  strcpy(pstr_, str);
  return *this;
}
String& String::operator=(const String& str) {
  delete pstr_;
  pstr_ = new char[str.size()];
  strcpy(pstr_, str.pstr_);
  return *this;
}

String& String::operator+=(const char* str) {
  char* str_temp = new char[size() + strlen(str) + 1];
  strcpy(str_temp, pstr_);
  strcat(str_temp, str);
  delete pstr_;
  pstr_ = str_temp;
  return *this;
}
String& String::operator+=(const String& str) {
  char* str_temp = new char[size() + str.size() + 1];
  strcpy(str_temp, pstr_);
  strcat(str_temp, str.pstr_);
  delete pstr_;
  pstr_ = str_temp;
  return *this;
}

char& String::operator[](size_t index) { return *(pstr_ + index); }
const char& String::operator[](size_t index) const { return *(pstr_ + index); }
// cosnt修饰的对象只能调用const成员函数,普通对象就调用上面这个非const版本
// const成员函数内无法修改数据成员,也无法调用非const成员函数

size_t String::size() const {
  size_t size = 0;
  while (pstr_ && pstr_[size]) {
    size++;
  }
  return size;
}

const char* String::c_str() const { return pstr_; }

bool operator==(const String& lhs, const String& rhs) {
  // if (lhs.pstr_ == nullptr || rhs.pstr_ == nullptr) {
  //   return false;
  // } else //此处应该有异常处理
    return 0 == strcmp(lhs.pstr_, rhs.pstr_);
  
}
bool operator!=(const String& lhs, const String& rhs) {
  return 0 != strcmp(lhs.pstr_, rhs.pstr_);
}

bool operator<(const String& lhs, const String& rhs) {
  return strcmp(lhs.pstr_, rhs.pstr_) < 0;
}
bool operator>(const String& lhs, const String& rhs) {
  return strcmp(lhs.pstr_, rhs.pstr_) > 0;
}
bool operator<=(const String& lhs, const String& rhs) {
  return !(strcmp(lhs.pstr_, rhs.pstr_) > 0);
}
bool operator>=(const String& lhs, const String& rhs) {
  return !(strcmp(lhs.pstr_, rhs.pstr_) < 0);
}

std::ostream& operator<<(std::ostream& os, const String& s) {
  size_t i = 0;
  while (i < s.size()) {
    os << s[i++];
  }
  return os;
}
std::istream& operator>>(std::istream& is, String& s) {
  delete s.pstr_;
  s.pstr_ = new char[sizeof(is)];
  is >> s.pstr_;
  return is;
}

String operator+(const String& lhs, const String& rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}
String operator+(const String& lhs, const char* rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}
String operator+(const char* lhs, const String& rhs) {
  String temp(lhs);
  temp += rhs;
  return temp;
}
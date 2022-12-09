#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>

using namespace std;

class String {
 public:
  String();
  String(const char*);
  String(const String&);
  ~String();

  // move constructor
  String(String&& other);
  String& operator=(String&& rhs);

  String& operator=(const char*);
  String& operator=(const String&);

  String& operator+=(const char*);
  String& operator+=(const String&);

  char& operator[](size_t index);
  const char& operator[](size_t index) const;

  size_t size() const;
  const char* c_str() const;

  friend bool operator==(const String&, const String&);
  friend bool operator!=(const String&, const String&);

  friend bool operator<(const String&, const String&);
  friend bool operator>(const String&, const String&);
  friend bool operator<=(const String&, const String&);
  friend bool operator>=(const String&, const String&);

  friend std::ostream& operator<<(std::ostream& os, const String& s);
  friend std::istream& operator>>(std::istream& is, String& s);

 private:
  char* pstr_;
};
String operator+(const String&, const String&);
String operator+(const String&, const char*);
String operator+(const char*, const String&);

#endif  // MY_STRING_H_
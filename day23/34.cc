#include "main.h"

namespace {
using std::cout;
using std::endl;
using std::string;

class Student {
  friend void PrintDegree(const Student&);

 public:
  Student(const char* name, double score) : name_(name), score_(score) {}

 private:
  string name_;
  double score_;
};
void PrintDegree(const Student& stu) {
  if (stu.score_ >= 90) {
    cout << "优" << endl;
  } else if (stu.score_ >= 80) {
    cout << "良" << endl;
  } else if (stu.score_ >= 70) {
    cout << "中" << endl;
  } else if (stu.score_ >= 60) {
    cout << "及格" << endl;
  } else {
    cout << "不及格" << endl;
  }
}
}  // namespace

int Question34() {
  Student s1("xiaoming", 59);
  PrintDegree(s1);
  return 0;
}
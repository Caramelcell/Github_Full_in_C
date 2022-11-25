#ifndef MAIN_H_
#define MAIN_H_

#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

template <typename T>
int Swap(T& m1, T& m2) {
  if (m1 && m2) {
    T temp = m1;
    m1 = m2;
    m2 = temp;
    return 0;
  } else {
    return -1;
  }
}
template <typename T>
void PrintContainer(const T& t) {
  for (auto i : t) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

int Question31();
int Question32();
int Question33();
int Question34();
int Question35();
int Question36();
int Question37();
int Question38();
int Question39();
int Question40();
int Question41();
int Question42();
int Question43();
int Question44();
int Question45();
int Question46();
int Question47();
int Question48();
int Question49();
int Question50();
int Question51();
int Question52();
int Question53();
int Question54();
int Question55();
int Question56();
int Question57();
int Question58();
int Question59();
int Question60();

#endif  // MAIN_H_
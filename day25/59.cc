#include "main.h"

int Question59() {
  /*
  map中重载的[]运算符的目的是用key值来访问value，因此对map的迭代器进行解引用得到的是一个pair类型的元素，即map中的元素都是pair类型的
  故map的下标运算符返回的是pair.second，下标运算符中间填写的值为pair.first

  以Question57为例，在map<string, vector<string>> rgs_table;中，map的元素类型是pair<string, vector<string>>，rgs_table["string"]返回的是一个vector<string>，而对map<string, vector<string>>::iterator这个迭代器类型的对象进行解引用得到的是一个pair<string, vector<string>>元素
  */

  return 0;
}
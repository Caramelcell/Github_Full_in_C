#include "main.h"

int Question58() {
  using std::cin;
  using std::string;
  using std::vector;

  string buf;
  vector<string> v_words;
  while (cin >> buf) {
    int flag = 0;
    for (auto i : v_words) {
      if (buf == i) {
        flag = 1;
        break;
      }
    }
    if (flag) {
      continue;
    } else {
      v_words.push_back(buf);
    }
  }
  PrintContainer(v_words);
  /*
  使用set的优点在于保存单词时不需要再对容器遍历一遍来寻找是否已经保存过该单词了，set的特点就是key即value，相同的key不会重复加入容器。
  */
  return 0;
}
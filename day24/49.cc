#include "main.h"

int Question49() {
  /*
  (1)因为要按字典序插入就代表需要频繁的进行插入操作，且插入位置未知，用list稍微比另两个容器好，因为链表在进行插入操作时不需要进行移动元素的操作，事实上用map比list更好
  (2)因为新单词要在尾部插入，删除要在头部删除，所以双端队列deque比较适合
  (3)因为要将未知数量的整数进行排序，需要能够随机访问，所以用vector比较适合
  */
  return 0;
}
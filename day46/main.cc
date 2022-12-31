#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  class Solution {
   public:
    int myAtoi(string s) {
      int max_int = 0x7FFFFFFF;
      int min_int = 0x80000000;
      int ret = 0;
      int i = 0;
      bool flag = true;
      while (i < s.size() && s[i] == ' ') {
        ++i;
      }
      if (i < s.size() && s[i] == '-') {
        flag = false;
        ++i;
      } else if (s[i] == '+') {
        ++i;
      }
      while (i < s.size()) {
        if (s[i] >= '0' && s[i] <= '9') {
          if (ret > max_int / 10) return flag ? max_int : min_int;
          if (ret == max_int / 10 && s[i] > '7')
            return flag ? max_int : min_int;
          ret = ret * 10 + (s[i] - '0');
        } else {
          break;
        }
        ++i;
      }
      return flag ? ret : -ret;
    }
  };
  Solution test;
  string s = "2147483646";
  cout << test.myAtoi(s) << endl;
}
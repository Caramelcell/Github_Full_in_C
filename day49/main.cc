#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  class Solution {
   public:
    int romanToInt(string s) {
      unordered_map<char, int> num = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};
      int pre{0}, cur{1}, ret{0};
      int len = s.size();
      while (cur < len) {
        if (s[pre] == 'I' && s[cur] == 'V') {
          ret += 4;
          pre += 2;
          cur += 2;
          continue;
        }
        if (s[pre] == 'I' && s[cur] == 'X') {
          ret += 9;
          pre += 2;
          cur += 2;
          continue;
        }
        if (s[pre] == 'X' && s[cur] == 'L') {
          ret += 40;
          pre += 2;
          cur += 2;
          continue;
        }
        if (s[pre] == 'X' && s[cur] == 'C') {
          ret += 90;
          pre += 2;
          cur += 2;
          continue;
        }
        if (s[pre] == 'C' && s[cur] == 'D') {
          ret += 400;
          pre += 2;
          cur += 2;
          continue;
        }
        if (s[pre] == 'C' && s[cur] == 'M') {
          ret += 900;
          pre += 2;
          cur += 2;
          continue;
        }
        ret += num[s[pre]];
        ++pre;
        ++cur;
      }
      if (pre < len) ret += num[s[pre++]];
      return ret;
    }
  };
  Solution test;
  string s = "CMXCIX";
  cout << test.romanToInt(s) << endl;
}
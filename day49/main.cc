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
      int pre{0}, ret{0};
      int len = s.size();
      while (pre < len) {
        if (pre < len - 1 && num[s[pre]] < num[s[pre + 1]])
          ret -= num[s[pre]];
        else
          ret += num[s[pre]];
        ++pre;
      }
      return ret;
    }
  };
  Solution test;
  string s = "CMXCIX";
  cout << test.romanToInt(s) << endl;
}
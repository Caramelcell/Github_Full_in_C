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
    int strStr(string haystack, string needle) {
      int ret = -1;
      int haystack_len = haystack.size();
      int needle_len = needle.size();
      if (needle_len > haystack_len) return ret;
      int i = 0;
      while (i <= haystack_len - needle_len) {
        if (haystack[i] == needle[0]) {
          string temp = haystack.substr(i,needle_len);
          if (temp == needle) {
            ret = i;
            return ret;
          }
        }
        ++i;
      }
      return ret;
    }
  };
  Solution test;
  vector<string> str = {"hello", "ll", "flight"};
  cout << test.strStr(str[0],str[1]) << endl;
}
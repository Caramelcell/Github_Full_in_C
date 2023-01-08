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
    string longestCommonPrefix(vector<string>& strs) {
      string ret = strs[0];
      int i = 1;
      while (ret.size() && i < strs.size()) {
        int j = 0;
        while (j < ret.size() && j < strs[i].size()) {
          if (ret[j] != strs[i][j]) break;
          ++j;
        }
        ret = strs[i].substr(0, j);
        ++i;
      }
      return ret;
    }
  };
  Solution test;
  vector<string> str = {"flower", "flow", "flight"};
  cout << test.longestCommonPrefix(str) << endl;
}
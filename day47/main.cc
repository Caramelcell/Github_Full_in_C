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
    char repeatedCharacter(string s) {
      unordered_set<char> char_table;
      int i;
      for (i = 0; i < s.size(); ++i) {
        if (char_table.count(s[i]) == 1) break;
        char_table.insert(s[i]);
      }
      return s[i];
    }
  };
  Solution test;
  string s = "2147483646";
  cout << test.repeatedCharacter(s) << endl;
}
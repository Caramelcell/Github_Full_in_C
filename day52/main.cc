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
  // class Solution {
  //  public:
  //   string countAndSay(int n) {
  //     string pre_str{"1"};
  //     string cur_str, ret_str;
  //     while (n > 1) {
  //       int start_pos = 0;
  //       int i;
  //       for (i = 0; i < pre_str.size() - 1; ++i) {
  //         if (pre_str[i] != pre_str[i + 1]) {
  //           cur_str.push_back('1' + i - start_pos);
  //           cur_str.push_back(pre_str[i]);
  //           start_pos = i + 1;
  //         }
  //       }
  //       cur_str.push_back('1' + i - start_pos);
  //       cur_str.push_back(pre_str[i]);

  //       ret_str = cur_str;
  //       pre_str = cur_str;
  //       cur_str.clear();
  //       --n;
  //     }
  //     return ret_str;
  //   }
  // };
  class Solution {
   public:
    bool isInteger(string s) {
      bool ret = false;
      int a;
      if (s.size() == 1) {
        a = s[0] - '0';
        if (a >= 0 && a <= 9) ret = true;
      } else if (s.size() > 1) {
        int i = 0;
        if (s[0] == '+' || s[0] == '-') i = 1;
        for (; i < s.size(); ++i) {
          a = s[i] - '0';
          if (a < 0 || a > 9) break;
        }
        if (i == s.size()) ret = true;
      }
      return ret;
    }
    bool isDecimal(string s) {
      bool ret = false;
      if (s.size() < 2) return ret;
      int dot_pos = -1;
      for (int i = 0; i < s.size(); ++i) {
        if (dot_pos != -1 && s[i] == '.') return ret;
        if (s[i] == '.') dot_pos = i;
      }
      if (dot_pos == -1) return ret;
      string str1, str2;
      str1 = s.substr(0, dot_pos);
      if (dot_pos < s.size() - 1) str2 = s.substr(dot_pos + 1, s.size());
      if (str2.size() > 0 && (str2[0] == '+' || str2[0] == '-')) return ret;
      if (str1.size() == 0 || str1 == "+" || str1 == "-")
        ret = this->isInteger(str2);
      else if (str2.size() == 0)
        ret = this->isInteger(str1);
      else
        ret = this->isInteger(str2) && this->isInteger(str1);
      return ret;
    }
    bool isNumber(string s) {
      bool ret = false;
      int split_pos = -1;
      string str1, str2;
      for (int i = 0; i < s.size(); ++i) {
        // two e/E
        if (split_pos != -1 && (s[i] == 'e' || s[i] == 'E')) return ret;
        // find e/E
        if (s[i] == 'e' || s[i] == 'E') split_pos = i;
      }
      if (split_pos != -1) {
        str1 = s.substr(0, split_pos);
        if (split_pos < s.size() - 1) str2 = s.substr(split_pos + 1, s.size());
        ret = (this->isDecimal(str1) || this->isInteger(str1)) &&
              this->isInteger(str2);
      } else {
        ret = this->isDecimal(s) || this->isInteger(s);
      }
      return ret;
    }
  };
  Solution test;
  vector<string> str = {"hello", "ll", "flight"};
  cout << test.isNumber("0") << endl;
}
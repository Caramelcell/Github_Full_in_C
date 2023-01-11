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
  //   string addBinary(string a, string b) {
  //     string temp;
  //     int carry_flag = 0;
  //     int i = a.size() - 1;
  //     int j = b.size() - 1;
  //     while (i >= 0 || j >= 0) {
  //       int a_num = 0, b_num = 0;
  //       if (i >= 0) a_num = a[i--] - '0';
  //       if (j >= 0) b_num = b[j--] - '0';
  //       int subsum = a_num + b_num + carry_flag;
  //       switch (subsum) {
  //         case 0:
  //           temp += "0";
  //           break;
  //         case 1:
  //           temp += "1";
  //           carry_flag = 0;
  //           break;
  //         case 2:
  //           temp += "0";
  //           carry_flag = 1;
  //           break;
  //         case 3:
  //           temp += "1";
  //           carry_flag = 1;
  //           break;
  //         default:
  //           break;
  //       }
  //     }
  //     if (carry_flag) temp += "1";
  //     string ret(temp.rbegin(), temp.rend());
  //     return ret;
  //   }
  // };
  // class Solution {
  //  public:
  //   bool isPalindrome(string s) {
  //     string filter_s;
  //     for (auto i = s.begin(); i != s.end(); ++i) {
  //       if (*i >= 'A' && *i <= 'Z') {
  //         filter_s.push_back(*i - 'A' + 'a');
  //       } else if ((*i >= 'a' && *i <= 'z') || (*i >= '0' && *i <= '9')) {
  //         filter_s.push_back(*i);
  //       }
  //     }
  //     int i = 0;
  //     int j = filter_s.size() - 1;
  //     while (i < j) {
  //       if (filter_s[i++] != filter_s[j--]) return false;
  //     }
  //     return true;
  //   }
  // };
  class Solution {
   public:
    string addStrings(string num1, string num2) {
      string temp;
      int carry_flag = 0;
      int i = num1.size() - 1;
      int j = num2.size() - 1;
      while (i >= 0 || j >= 0) {
        int num1_num = 0, num2_num = 0;
        if (i >= 0) num1_num = num1[i--] - '0';
        if (j >= 0) num2_num = num2[j--] - '0';
        int subsum = num1_num + num2_num + carry_flag;
        temp.push_back(subsum % 10 + '0');
        carry_flag = subsum / 10;
      }
      if (carry_flag) temp.push_back('1');
      string ret(temp.rbegin(), temp.rend());
      return ret;
    }
  };
  Solution test;
  vector<string> str = {"9133", "0", "flight"};
  cout << test.addStrings(str[0], str[1]) << endl;
}
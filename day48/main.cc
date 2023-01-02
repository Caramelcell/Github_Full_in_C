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
    string intToRoman(int num) {
      unordered_map<int, vector<string>> roman_num = {
          {1, {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}},
          {10, {"X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}},
          {100, {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}},
          {1000, {"M", "MM", "MMM"}},
      };
      string ret;
      int div_num = 1000;
      int bit_num;
      while (num && div_num) {
        bit_num = num / div_num;
        if (bit_num) {
          ret += roman_num[div_num][bit_num - 1];
        }
        num %= div_num;
        div_num /= 10;
      }
      return ret;
    }
  };
  Solution test;
  cout << test.intToRoman(3999) << endl;
}
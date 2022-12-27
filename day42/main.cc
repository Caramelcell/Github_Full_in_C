#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  // leetcode Q80
  // class Solution {
  //  public:
  //   int removeDuplicates(vector<int>& nums) {
  //     pair<int, int> ans_state = {0, 1};
  //     int check = 1;
  //     while (check < nums.size()) {
  //       if (nums[check] == nums[ans_state.first]) {
  //         if (ans_state.second == 1) {
  //           ans_state.first += 1;
  //           ans_state.second = 2;
  //           nums[ans_state.first] = nums[check];
  //         }
  //         ++check;
  //       } else {
  //         ans_state.first += 1;
  //         ans_state.second = 1;
  //         nums[ans_state.first] = nums[check++];
  //       }
  //     }
  //     return ans_state.first + 1;
  //   }
  // };
  class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
      if (nums.size() == 0) return 0;
      // sort(nums.begin(), nums.end());
      unordered_set<int> nums_set(nums.begin(), nums.end());
      int ans = 1, temp = 1, value;
      auto update = [&ans](int newans) {
        if (newans > ans) {
          ans = newans;
        }
      };
      for (auto i = nums_set.begin(); i != nums_set.end(); ++i) {
        value = *i;
        //判断是否是连续序列最小值
        if(nums_set.count(value - 1)) continue;
        //计算连续序列大小
        while(nums_set.count(++value)){
          temp++;
        }
        update(temp);
        temp = 1;
      }
      return ans;
    }
  };
  Solution test;
  vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
  int result = test.longestConsecutive(nums);
  cout << result << endl;
}
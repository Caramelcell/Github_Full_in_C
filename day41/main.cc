#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main() {
  class Solution {
   public:
    int threeSumClosest(vector<int>& nums, int target) {
      sort(nums.begin(), nums.end());
      int i, j, k, result;
      result = nums[0] + nums[1] + nums[2];
      auto update = [=, &result](int newsum) {
        if (abs(newsum - target) < abs(result - target)) {
          result = newsum;
        }
      };
      for (i = 0; i < nums.size() - 2;) {
        for (j = i + 1, k = nums.size() - 1; j < k;) {
          update(nums[i] + nums[j] + nums[k]);
          if (nums[i] + nums[j] + nums[k] == target) {
            return target;
          } else if (nums[i] + nums[j] + nums[k] < target) {
            do {
              ++j;
            } while (j < k && nums[j - 1] == nums[j]);
          } else if (nums[i] + nums[j] + nums[k] > target) {
            do {
              --k;
            } while (j < k && nums[k] == nums[k + 1]);
          }
        }
        do {
          ++i;
        } while (i < nums.size() - 2 && nums[i - 1] == nums[i]);
      }
      return result;
    }
  };
  Solution test;
  vector<int> nums = {-100, -98, -2, -1};
  int result = test.threeSumClosest(nums, -101);
  cout << result << endl;
}
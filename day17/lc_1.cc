#include "main.h"

vector<int> Solution::twoSum(vector<int>& nums, int target) {
  vector<int> arr;
  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      if (target == nums.at(i) + nums.at(j)) {
        arr.push_back(i);
        arr.push_back(j);
        return arr;
      }
    }
  }
  return arr;
}
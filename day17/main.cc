#include "main.h"

int main() {
  // int arr[6] = {1, 2, 3, 4, 5, 6};
  // vector<int, allocator<int>> varr(arr, arr + 6);
  // // vector存放的是int类型的数据
  // //
  // allocator是container_adapters/容器适配器,告诉编译器以这种方式来给数据分配空间(分配内存),一般默认可不写
  // cout << count_if(varr.begin(), varr.end(), not1(bind2nd(less<int>(), 3)))
  //      << endl;
  // //count_if是algorithm/算法
  // //varr.begin(), varr.end()这部分是iterator/迭代器
  vector<int> nums = {2, 7, 15, 11};
  vector<int> arr;
  int target = 9;
  Solution Question1;
  arr = Question1.twoSum(nums, target);
  for (auto i : arr) {
    cout << i;
  }

  return 0;
}
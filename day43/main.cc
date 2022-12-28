#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
  class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int oil_tank = 0;
      int i, j;
      for (i = 0; i < gas.size(); ++i) {
        // 从第i个加油站开车
        oil_tank = gas[i];
        // if (gas[i] == 0 || cost[(i - 1 + cost.size()) % cost.size()] == 0)
        //   continue;
        for (j = 0; j < gas.size(); ++j) {
          // 行驶次数
          int temp_cost = (i + j) % gas.size();
          int temp_gas = (i + j + 1) % gas.size();
          if (cost[temp_cost] > oil_tank) {
            // 油不够
            i = i + j;
            break;
          } else {
            oil_tank = oil_tank - cost[temp_cost] + gas[temp_gas];
          }
        }
        if (j == gas.size()) {
          // 找到答案
          break;
        }
      }
      if (j == gas.size()) {
        return i;
      } else {
        return -1;
      }
    }
  };
  Solution test;
  vector<int> gas = {2,3,4};
  vector<int> cost = {3,4,3};
  int result = test.canCompleteCircuit(gas, cost);
  cout << result << endl;
}
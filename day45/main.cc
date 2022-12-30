#include <algorithm>
#include <deque>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
ListNode* creat_list(vector<int> nums) {
  ListNode* ret = new ListNode(nums[0]);
  ListNode* head = ret;
  for (int i = 1; i < nums.size(); ++i) {
    ret->next = new ListNode(nums[i]);
    ret = ret->next;
  }
  return head;
}
ListNode* ReverseList(ListNode* head) {
  if (head->next == nullptr) return head;
  ListNode* pre = nullptr;
  ListNode* cur = head;
  while (head->next) {
    head = head->next;
    cur->next = pre;
    pre = cur;
    cur = head;
  }
  head->next = pre;
  return head;
}
ListNode* ListMid(ListNode* const head) {
  if (head->next == nullptr) return head;
  ListNode *slow, *fast;
  slow = fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
void MergeList(ListNode* to_list, ListNode* from_list) {
  ListNode* to_pre = to_list;
  ListNode* to_cur = to_list->next;
  ListNode* from_pre = from_list;
  ListNode* from_cur = from_list->next;
  while (from_cur && to_cur) {
    to_pre->next = from_pre;
    from_pre->next = to_cur;
    to_pre = to_cur;
    from_pre = from_cur;
    to_cur = to_cur->next;
    from_cur = from_cur->next;
  }
  to_pre->next = from_pre;
}
int main() {
  // class Solution {
  //  public:
  //   bool hasCycle(ListNode* head) {
  //     set<ListNode*> s;
  //     ListNode* ptr = head;
  //     while (ptr) {
  //       if (s.count(ptr) == 0) {
  //         s.insert(ptr);
  //         ptr = ptr->next;
  //       } else {
  //         return true;
  //       }
  //     }
  //     return false;
  //   }
  // };
  class Solution {
   public:
    void reorderList(ListNode* head) {
      // deque<ListNode*> d;
      // ListNode* ptr = head;
      // while (ptr) {
      //   d.emplace_back(ptr);
      //   ptr = ptr->next;
      // }
      // int count = 1;
      // ptr = head;
      // d.pop_front();
      // while (d.size() > 0) {
      //   if (count % 2) {
      //     ptr->next = d.back();
      //     ptr = ptr->next;
      //     d.pop_back();
      //   } else {
      //     ptr->next = d.front();
      //     ptr = ptr->next;
      //     d.pop_front();
      //   }
      //   ++count;
      // }
      // ptr->next = nullptr;
      // 解法2:
      ListNode* mid = ListMid(head);
      mid = ReverseList(mid);
      MergeList(head, mid);
    }
  };
  Solution test;
  vector<int> v1 = {1, 2, 3, 4};
  vector<int> v2 = {7, 3};
  ListNode* l1 = creat_list(v1);
  ListNode* l2 = creat_list(v2);
  // bool result = test.hasCycle(l1);
  test.reorderList(l1);
  for (auto i = l1; i != nullptr; i = i->next) {
    cout << i->val << " ";
  }
  cout << endl;
}
#include <algorithm>
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
ListNode* ReverseList(ListNode* head, ListNode* tail) {
  if (head->next == nullptr) return head;
  ListNode* pre = nullptr;
  ListNode* cur = head;
  ListNode* nhead = head;
  while (nhead != tail) {
    nhead = nhead->next;
    cur->next = pre;
    pre = cur;
    cur = nhead;
  }
  nhead->next = pre;
  tail = head;
  head = nhead;
  return head;
}
int main() {
  class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (head->next == nullptr) return head;
      ListNode *pleft, *pright, *ppre, *psuc;
      ListNode* dummy = new ListNode(0, head);
      ListNode* temp = dummy;
      for (int count = 0; count <= right; ++count) {
        if (count == left - 1) {
          ppre = temp;
        } else if (count == left) {
          pleft = temp;
        }
        if (count == right) {
          pright = temp;
        }
        temp = temp->next;
      }
      psuc = pright->next;
      ReverseList(pleft, pright);
      ppre->next = pright;
      pleft->next = psuc;
      head = dummy->next;
      delete dummy;
      return head;
    }
  };
  Solution test;
  vector<int> v1 = {1, 2, 3, 4, 5};
  vector<int> v2 = {7, 3};
  ListNode* l1 = creat_list(v1);
  ListNode* l2 = creat_list(v2);
  ListNode* result = test.reverseBetween(l1, 2, 4);
  ListNode* head = result;
  while (head) {
    cout << head->val << ",";
    head = head->next;
  }
  cout << endl;
}
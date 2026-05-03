#include <bits/stdc++.h>
using namespace std;

// 2130. Maximum Twin Sum of a Linked List [M]
// LeetCode maximum-twin-sum-of-a-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* slowNext = slow->next;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(pre != slow) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        int ans = INT_MIN;
        while(slow) {
            ans = max(ans, slow->val + slowNext->val);
            slow = slow->next;
            slowNext = slowNext->next;
        }
        return ans;
    }
};
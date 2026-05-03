#include <bits/stdc++.h>
using namespace std;

// 2. Add Two Numbers [M]
// LeetCode add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2) {
            int val = carry;
            if(l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
        }
        if(carry) {
            cur->next = new ListNode(carry);
        }
        return dummy->next;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 1290. Convert Binary Number in a Linked List to Integer [E]
// LeetCode convert-binary-number-in-a-linked-list-to-integer

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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while(head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};
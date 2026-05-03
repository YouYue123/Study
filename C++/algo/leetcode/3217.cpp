#include <bits/stdc++.h>
using namespace std;

// 3217. Delete Nodes From Linked List Present in Array [M]
// LeetCode delete-nodes-from-linked-list-present-in-array

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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> dict(nums.begin(), nums.end());
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        ListNode* next = head;
        while(next) {
            cout << next->val << endl;
            if(!dict.contains(next->val)) {
                cur->next = next;
                cur = next;
            } 
            next = next->next;
        }
        cur->next = next;
        return dummy->next;
    }
};
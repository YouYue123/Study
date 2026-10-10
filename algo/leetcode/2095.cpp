#include <bits/stdc++.h>
using namespace std;

// 2095. Delete the Middle Node of a Linked List [M]
// LeetCode delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        dummyHead->next = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // cout << head << endl;
        // cout << slow->next << endl;
        slow->next = slow->next->next;
        return dummyHead->next;
    }
};
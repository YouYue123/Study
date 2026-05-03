#include <bits/stdc++.h>
using namespace std;

// 1474. Delete N Nodes After M Nodes of a Linked List [E]
// LeetCode delete-n-nodes-after-m-nodes-of-a-linked-list

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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        auto cur = head;
        auto last = head;
        while(cur != nullptr) {
            int mCount = m, nCount = n;
            while(cur != nullptr && mCount != 0) {
                last = cur;
                cur = cur->next;
                mCount -= 1;
            }
            while(cur != nullptr && nCount != 0) {
                cur = cur->next;
                nCount -= 1;
            }
            last->next = cur;
        }
        return head;
    }
};
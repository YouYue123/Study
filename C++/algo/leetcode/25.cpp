#include <bits/stdc++.h>
using namespace std;

// 25. Reverse Nodes in k-Group [H]
// LeetCode reverse-nodes-in-k-group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        int cnt = 0;
        ListNode* temp = dummy;
        while(temp->next) {
            cnt += 1;
            temp = temp->next;
        }
        ListNode* p0 = dummy;
        ListNode* prev = nullptr;
        ListNode* cur = p0->next;
        while(cnt >= k) {
            for(int i = 0; i < k; i ++) {
                ListNode* nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            p0->next->next = cur;
            ListNode* nxt = p0->next;
            p0->next = prev;
            p0 = nxt;
            prev = nullptr;
            cnt -= k;
        }
        return dummy->next;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 61. Rotate List [M]
// LeetCode rotate-list

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head) return head;
        int cnt = 0;
        ListNode* dummy = new ListNode(0, head);
        ListNode* tail = nullptr;
        while(head) {
            cnt += 1;
            tail = head;
            head = head->next;
        }
        ListNode* prev = dummy;
        for(int i = 0; i < cnt - k % cnt; i ++) {
            prev = prev->next;
        }
        tail->next = dummy->next;
        dummy->next = prev->next;
        prev->next = nullptr;
        return dummy->next;
    }
};
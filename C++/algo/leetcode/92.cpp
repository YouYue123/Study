// 92. Reverse Linked List II [M]
// LeetCode reverse-linked-list-ii

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* p0 = dummy;
        int cnt = 0;
        while(cnt < left - 1) {
            p0 = p0->next;
            cnt += 1;
        } 
        ListNode* prev = nullptr;
        ListNode* cur = p0->next;
        while(cnt < right) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            cnt += 1;
        }
        p0->next->next = cur;
        p0->next = prev;
        return dummy->next;
    }
};
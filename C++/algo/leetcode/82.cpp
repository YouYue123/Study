// 82. Remove Duplicates from Sorted List II [M]
// LeetCode remove-duplicates-from-sorted-list-ii

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur) {
            if(cur->next && cur->val == cur->next->val) {
                // cout << prev->val << endl;
                while(cur->next && cur->val == cur->next->val) {
                    cur = cur->next;
                }
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
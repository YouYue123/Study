// 83. Remove Duplicates from Sorted List [E]
// LeetCode remove-duplicates-from-sorted-list

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
        if(!head) return head;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while(nxt != nullptr) {
            if(cur->val == nxt->val) {
                cur->next = nxt->next;
                nxt = nxt->next;
            } else {
                cur = nxt;
                nxt = cur->next;
            }
        }
        return head;
    }
};
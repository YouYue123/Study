// 19. Remove Nth Node From End of List [M]
// LeetCode remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode *temp = head;
        int cnt = 0;
        while(temp) {
            cnt += 1;
            temp = temp->next;
        }
        int target = cnt - n;
        cnt = 0;
        // cout << target << endl;
        // cout << prev->next->val << endl;
        while(cnt < target) {
            prev = prev->next;
            cnt += 1;
        }
        // cout << prev->val << endl;
        prev->next = prev->next->next;
        return dummy->next;
    }
};
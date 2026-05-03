// 86. Partition List [M]
// LeetCode partition-list

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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* dummy1 = new ListNode(0, nullptr);
        ListNode* p0 = dummy1;
        ListNode* dummy2 = new ListNode(0, nullptr);
        ListNode* p1 = dummy2;
        while(head) {
            if(head->val < x) {
                p0->next = head;
                p0 = p0->next;
            } else {
                p1->next = head;
                p1 = p1->next;
            }
            head = head->next;
        }
        p0->next = dummy2->next;
        p1->next = nullptr;
        return dummy1->next;
    }
};
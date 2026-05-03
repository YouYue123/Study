// 1669. Merge In Between Linked Lists [M]
// LeetCode merge-in-between-linked-lists

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* left = nullptr;
        ListNode* right = list1;
        for(int i = 0; i < b; i ++) {
            if(i == a - 1) left = right;
            right = right->next;
        }
        left->next = list2;
        ListNode* tail = list2;
        while(tail->next) tail = tail->next;
        tail->next = right->next;
        right->next = nullptr;
        return list1;
    }
};
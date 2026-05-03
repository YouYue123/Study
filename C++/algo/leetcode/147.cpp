// 147. Insertion Sort List [M]
// LeetCode insertion-sort-list

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
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> arr;
        while(head) {
            arr.push_back(head);
            head = head->next;
        }
        sort(arr.begin(), arr.end(), [&] (ListNode* a, ListNode* b) {
            return a->val < b->val;
        });
        for(int i = 0; i < arr.size() - 1; i ++) {
            arr[i]->next = arr[i + 1];
        }
        arr[arr.size() - 1] ->next = nullptr;
        return arr[0];
    }
};
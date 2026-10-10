#include <bits/stdc++.h>
using namespace std;

// 23. Merge k Sorted Lists [H]
// LeetCode merge-k-sorted-lists

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
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(auto item : lists) {
            if(item) pq.push(item);
        }
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(!pq.empty()) {
            ListNode* candidate = pq.top();
            pq.pop();
            cur->next = candidate;
            cur = cur->next;
            if(candidate->next) pq.push(candidate->next);
        }
        // cur->next = nullptr;
        return dummy->next;
    }
};
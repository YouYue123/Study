#include <bits/stdc++.h>
using namespace std;

// 143. Reorder List [M]
// LeetCode reorder-list

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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* temp = head;
        while(temp) {
            s.push(temp);
            temp = temp->next;
        }
        ListNode* front = head;
        while(!s.empty()) {
            // cout << s.top()->val << endl;
            ListNode* last = s.top();
            s.pop();
            ListNode* next = front->next;
            if(last == next || last == front) {
                last->next = nullptr;
                break;
            }
            front->next = last;
            last->next = next;
            front = next;
        }
    }
};
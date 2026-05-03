#include <bits/stdc++.h>
using namespace std;

// 328. Odd Even Linked List [M]
// LeetCode odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* dummyOdd = new ListNode(0);
        ListNode* curOdd = dummyOdd;
        ListNode* dummyEven = new ListNode(0);
        ListNode* curEven = dummyEven;
        int i = 1;
        while(head) {
            if(i % 2 == 0) {
                curEven->next = head;
                curEven = curEven->next;
            } else {
                curOdd->next = head;
                curOdd = curOdd->next;
            }
            head = head->next;
            i += 1;
        }
        curOdd->next = dummyEven->next;
        curEven->next = nullptr;
        return dummyOdd->next;
    }
};
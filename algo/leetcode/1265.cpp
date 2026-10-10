#include <bits/stdc++.h>
using namespace std;

// 1265. Print Immutable Linked List in Reverse [M]
// LeetCode print-immutable-linked-list-in-reverse

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if(head == nullptr) return;
        if(head->getNext() == nullptr) {
            head->printValue();
            return;
        }
        printLinkedListInReverse(head->getNext());
        head->printValue();
        return;
    }
};
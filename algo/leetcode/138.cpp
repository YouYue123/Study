#include <bits/stdc++.h>
using namespace std;

// 138. Copy List with Random Pointer [M]
// LeetCode copy-list-with-random-pointer

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* originHead = head;
        unordered_map<Node*, Node*> dict;
        Node* dummy = new Node(0);
        Node* prev = dummy;
        while(head) {
            prev->next = new Node(head->val);
            dict[head] = prev->next;
            prev = prev->next;
            head = head->next;
        }
        head = originHead;
        while(head) {
            dict[head]->random = dict[head->random];
            head = head->next;
        }
        return dummy->next;
    }
};
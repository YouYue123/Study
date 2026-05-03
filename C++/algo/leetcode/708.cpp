// 708. Insert into a Sorted Circular Linked List [M]
// LeetCode insert-into-a-sorted-circular-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(head == nullptr) {
            newNode->next = newNode;
            return newNode;
        }
        Node* cur = head;
        while(cur->next != head) {
            if(cur->val <= cur->next->val) {
                // cout << "awer";
                if(cur->val <= insertVal && cur->next->val >= insertVal) break;
            } else {
                if(cur->val <= insertVal || cur->next->val >= insertVal) break;
            }
            cur = cur ->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        return head;
    }
};
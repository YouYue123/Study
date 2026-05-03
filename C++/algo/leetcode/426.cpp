// 426. Convert Binary Search Tree to Sorted Doubly Linked List [M]
// LeetCode convert-binary-search-tree-to-sorted-doubly-linked-list

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
 
    Node* treeToDoublyList(Node* root) {
        if(!root) return nullptr;
        Node* leftHead = treeToDoublyList(root->left);
        Node* rightHead = treeToDoublyList(root->right);
        Node* leftTail;
        Node* rightTail;
        if(leftHead) {
            leftTail = leftHead->left;
            root->left = leftTail;
            leftTail->right = root;
        } else {
            leftHead = root;
            leftTail = root;
        }
        if(rightHead) {
            rightTail = rightHead->left;
            root->right = rightHead;
            rightHead->left = root;
        } else {
            rightHead = root;
            rightTail = root;
        }
        leftHead->left = rightTail;
        rightTail->right = leftHead;
        return leftHead;
    }
};
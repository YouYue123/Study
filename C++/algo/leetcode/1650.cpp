// 1650. Lowest Common Ancestor of a Binary Tree III [M]
// LeetCode lowest-common-ancestor-of-a-binary-tree-iii

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        auto* a = p;
        auto* b = q;
        while(a != b) {
            a = (a ? a->parent : q);
            b = (b ? b->parent : p);
        }
        return a;
    }
};
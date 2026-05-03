// 1490. Clone N-ary Tree [M]
// LeetCode clone-n-ary-tree

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if(!root) return nullptr;
        Node* cur = new Node(root->val);
        for(int i = 0; i < root->children.size(); i ++) {
            cur->children.push_back(cloneTree(root->children[i]));
        }
        return cur;
    }
};
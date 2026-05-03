// 1506. Find Root of N-Ary Tree [M]
// LeetCode find-root-of-n-ary-tree

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
    Node* findRoot(vector<Node*> tree) {
        int sum = 0 ;
        for(Node* n: tree) {
            sum += n->val;
            for(Node* child: n->children) sum -= child->val;
        }
        for(Node* n: tree) {
            if(n->val == sum) return n;
        }
        return nullptr;
    }
};
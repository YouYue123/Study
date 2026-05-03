// 235. Lowest Common Ancestor of a Binary Search Tree [M]
// LeetCode lowest-common-ancestor-of-a-binary-search-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        } 
        if(root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else {
            return root;
        }
    }
};
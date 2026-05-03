// 114. Flatten Binary Tree to Linked List [M]
// LeetCode flatten-binary-tree-to-linked-list

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* cur = root->left;
        if(!cur) return;
        while(cur->right) cur = cur->right;
        cur->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};
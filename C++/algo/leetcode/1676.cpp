// 1676. Lowest Common Ancestor of a Binary Tree IV [M]
// LeetCode lowest-common-ancestor-of-a-binary-tree-iv

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
    unordered_set<TreeNode*> dict;
    TreeNode* dfs(TreeNode* root) {
        if(!root) return root;
        if(dict.contains(root)) return root;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left && right) return root;
        return left ? left : right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        for(TreeNode* node : nodes) dict.insert(node);
        return dfs(root);
    }
};
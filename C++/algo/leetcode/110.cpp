// 110. Balanced Binary Tree [E]
// LeetCode balanced-binary-tree

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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        auto dfs = [&] (this auto&& dfs, TreeNode* root) {
            if(!root) return 0;
            int left_len = dfs(root->left) + 1;
            int right_len = dfs(root->right) + 1;
            if(abs(left_len - right_len) > 1) ans = false;
            return max(left_len, right_len);
        };
        dfs(root);
        return ans;
    }
};
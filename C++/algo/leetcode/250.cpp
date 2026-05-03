// 250. Count Univalue Subtrees [M]
// LeetCode count-univalue-subtrees

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
    int ans = 0;
    bool dfs(TreeNode* root, int parentVal) {
        if(root == nullptr) return true;
        bool leftValid = dfs(root->left, root->val);
        bool rightValid = dfs(root->right, root->val);
        if(leftValid && rightValid) {
            ans += 1;
            return parentVal == root->val;
        }
        return false;
    }
     int countUnivalSubtrees(TreeNode* root) {
        dfs(root, -1);
        return ans;
    }
};
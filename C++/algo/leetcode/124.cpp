// 124. Binary Tree Maximum Path Sum [H]
// LeetCode binary-tree-maximum-path-sum

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
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = -INF;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return 0;
            int left = dfs(cur->left);
            int right = dfs(cur->right);
            int max_conbrib = max(max(left, right), 0);
            ans = max({
                ans,
                left + right + cur->val,
                max_conbrib + cur->val,
            });
            return max_conbrib + cur->val;
        };
        dfs(root);
        return ans;
    }
};
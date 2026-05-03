// 1339. Maximum Product of Splitted Binary Tree [M]
// LeetCode maximum-product-of-splitted-binary-tree

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
int MOD = 1e9 + 7;
class Solution {
public:
    int maxProduct(TreeNode* root) {
        long long ans = 0;
        long long total_sum = 0;
        auto get_total_sum = [&] (this auto&& dfs, TreeNode* cur) -> void {
            if(!cur) return;
            dfs(cur->left);
            dfs(cur->right);
            total_sum += cur->val;
        };
        get_total_sum(root);
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return 0;
            int left_sum = dfs(cur->left);
            int right_sum = dfs(cur->right);
            ans = max({
                ans,
                1LL * left_sum * (total_sum - left_sum),
                1LL * (total_sum - right_sum) * right_sum
            });
            // cout << "cur: " << cur->val << endl;
            // cout << "parent_sum(including this): " << nxt_parent_sum << endl;
            // cout << left_sum << " " << right_sum << endl;
            return left_sum + right_sum + cur->val;
        };
        dfs(root);
        return ans % MOD;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 129. Sum Root to Leaf Numbers [M]
// LeetCode sum-root-to-leaf-numbers

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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur, int val) {
            if(!cur) return;
            int nxt_val = val * 10 + cur->val;
            if(cur->left) dfs(cur->left, nxt_val);
            if(cur->right) dfs(cur->right, nxt_val);
                        if(!cur->left && !cur->right) {
                ans += nxt_val;
                return;
            }
        };
        dfs(root, 0);
        return ans;
    }
};
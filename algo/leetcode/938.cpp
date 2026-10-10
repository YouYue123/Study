#include <bits/stdc++.h>
using namespace std;

// 938. Range Sum of BST [E]
// LeetCode range-sum-of-bst

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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return;
            if(cur->val < low) {
                dfs(cur->right);
            } else if(cur->val > high) {
                dfs(cur->left);
            } else {
                ans += cur->val;
                dfs(cur->left);
                dfs(cur->right);
            }
        };
        dfs(root);
        return ans;
    }
};
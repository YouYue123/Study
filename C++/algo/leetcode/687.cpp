#include <bits/stdc++.h>
using namespace std;

// 687. Longest Univalue Path [M]
// LeetCode longest-univalue-path

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
    int longestUnivaluePath(TreeNode* root) {
        int final_ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) -> int{
            int left_path = 0, right_path = 0;
            if(cur) {
                if(cur->left) {
                    if(cur->val == cur->left->val) {
                        left_path = 1 + dfs(cur->left);
                    } else {
                        final_ans = max(final_ans, dfs(cur->left));
                    }
                } 
                if(cur->right) {
                    if(cur->val == cur->right->val) {
                        right_path = 1 + dfs(cur->right);
                    } else {
                        final_ans = max(final_ans, dfs(cur->right));
                    }
                }
            }
            final_ans = max(final_ans, left_path + right_path);
            return max(left_path, right_path); 
        };
        dfs(root);
        return final_ans;
    }
};
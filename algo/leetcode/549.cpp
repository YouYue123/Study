#include <bits/stdc++.h>
using namespace std;

// 549. Binary Tree Longest Consecutive Sequence II [M]
// LeetCode binary-tree-longest-consecutive-sequence-ii

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
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur, int parent_val) -> pair<int, int> {
            if(!cur) return { 0, 0 };
            auto [leftI, leftD] = dfs(cur->left, cur->val);
            auto [rightI, rightD] = dfs(cur->right, cur->val);
            ans = max({
                ans,
                leftI + rightD + 1,
                leftD + rightI + 1
            });
            if(parent_val - cur->val == 1) {
                return {
                    max(leftI, rightI) + 1,
                    0
                };
            } 
            if(parent_val - cur->val == -1) {
                return {
                    0,
                    max(leftD, rightD) + 1,
                };
            }
            return {0, 0}; 
        };
        dfs(root, 0);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 298. Binary Tree Longest Consecutive Sequence [M]
// LeetCode binary-tree-longest-consecutive-sequence

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
        auto isChildValid = [&] (TreeNode* cur, TreeNode* child) {
            return child == nullptr || cur->val + 1 == child->val;
        };
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(cur == nullptr) return 0;
            int left  = 1 + dfs(cur->left);
            int right = 1 + dfs(cur->right);
            if(!isChildValid(cur, cur->left)) left = 1;
            if(!isChildValid(cur, cur->right)) right = 1;
            int curAns = max(left, right);
            ans = max(ans, curAns);
            return curAns;
        };
        dfs(root);
        return ans;
    }
};
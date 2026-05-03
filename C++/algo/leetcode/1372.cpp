#include <bits/stdc++.h>
using namespace std;

// 1372. Longest ZigZag Path in a Binary Tree [M]
// LeetCode longest-zigzag-path-in-a-binary-tree

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
    pair<int, int> dfs(TreeNode* root) {
        if(!root) return { -1, -1 };
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int rootPathLen1 = left.second + 1;
        int rootPathLen2 = right.first + 1;
        ans = max(ans, max(rootPathLen1, rootPathLen2));
        return {rootPathLen1, rootPathLen2};
    }
    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
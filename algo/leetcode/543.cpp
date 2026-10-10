#include <bits/stdc++.h>
using namespace std;

// 543. Diameter of Binary Tree [E]
// LeetCode diameter-of-binary-tree

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return 0;
            int left = dfs(cur->left);
            int right = dfs(cur->right);
            ans = max(ans, left + right);
            return max(left, right) + 1;
        };
        dfs(root);
        return ans;
    }
};
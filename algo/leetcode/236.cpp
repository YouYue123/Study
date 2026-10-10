#include <bits/stdc++.h>
using namespace std;

// 236. Lowest Common Ancestor of a Binary Tree [M]
// LeetCode lowest-common-ancestor-of-a-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return cur;
            auto* left = dfs(cur->left);
            auto* right = dfs(cur->right);
            if(cur == p || cur == q) return cur;
            if(left && right) return cur;
            return left ? left : right;
        };
        return dfs(root);
    }
};
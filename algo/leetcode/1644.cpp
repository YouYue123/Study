#include <bits/stdc++.h>
using namespace std;

// 1644. Lowest Common Ancestor of a Binary Tree II [M]
// LeetCode lowest-common-ancestor-of-a-binary-tree-ii

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
        bool find_p = false, find_q = false;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return cur;
            auto* left = dfs(cur->left);
            auto* right = dfs(cur->right);
            if(cur == p) find_p = true;
            if(cur == q) find_q = true;
            if(cur == p || cur == q) return cur;
            if(left && right) return cur;
            return left ? left : right;
        };
        auto* ans = dfs(root);
        if(find_p && find_q) return ans;
        return nullptr;
    }
};
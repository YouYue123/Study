#include <bits/stdc++.h>
using namespace std;

// 98. Validate Binary Search Tree [M]
// LeetCode validate-binary-search-tree

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
    bool dfs(TreeNode* root, long long curMax, long long curMin) {
        if(!root) return true;
        if(root->val >= curMax || root->val <= curMin) return false;
        return dfs(root->left, root->val, curMin) && dfs(root->right, curMax, root->val);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
};
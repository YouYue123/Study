#include <bits/stdc++.h>
using namespace std;

// 1026. Maximum Difference Between Node and Ancestor [M]
// LeetCode maximum-difference-between-node-and-ancestor

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
    int dfs(TreeNode* root, int curMax, int curMin) {
        if(!root) return curMax - curMin;
        curMax = max(curMax, root->val);
        curMin = min(curMin, root->val);
        int left = dfs(root->left, curMax, curMin);
        int right = dfs(root->right, curMax, curMin);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return dfs(root, root->val, root->val);
    }
};
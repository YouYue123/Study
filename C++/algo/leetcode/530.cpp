#include <bits/stdc++.h>
using namespace std;

// 530. Minimum Absolute Difference in BST [E]
// LeetCode minimum-absolute-difference-in-bst

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
    TreeNode* prev;
    int ans = INT_MAX;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(prev) ans = min(ans, root->val - prev->val);
        prev = root;
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
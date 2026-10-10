#include <bits/stdc++.h>
using namespace std;

// 783. Minimum Distance Between BST Nodes [E]
// LeetCode minimum-distance-between-bst-nodes

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
    int ans = INT_MAX;
    TreeNode* prev = nullptr;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(prev) ans = min(ans, abs(prev->val - root->val));
        prev = root;
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
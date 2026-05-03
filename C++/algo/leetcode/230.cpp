#include <bits/stdc++.h>
using namespace std;

// 230. Kth Smallest Element in a BST [M]
// LeetCode kth-smallest-element-in-a-bst

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
    int cur = 0;
    int ans = 0;
    void dfs(TreeNode* root, int k) {
        if(!root || cur == k) return;
        dfs(root->left, k);
        if(cur == k) return;
        cur += 1;
        ans = root->val;
        dfs(root->right, k);
    } 
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return ans;
    }
};
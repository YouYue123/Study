#include <bits/stdc++.h>
using namespace std;

// 1038. Binary Search Tree to Greater Sum Tree [M]
// LeetCode binary-search-tree-to-greater-sum-tree

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
    int preSum = 0;
    TreeNode* bstToGst(TreeNode* root) {
        if(!root) return root;
        bstToGst(root->right);
        int temp = root->val;
        root->val += preSum;
        preSum += temp;
        bstToGst(root->left);
        return root;
    }
};
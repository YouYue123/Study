#include <bits/stdc++.h>
using namespace std;

// 538. Convert BST to Greater Tree [M]
// LeetCode convert-bst-to-greater-tree

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
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return root;
        convertBST(root->right);
        int temp = root->val;
        root->val += preSum;
        preSum += temp;
        convertBST(root->left);
        return root;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 545. Boundary of Binary Tree [M]
// LeetCode boundary-of-binary-tree

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
    vector<int> ans;
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        ans.push_back(root->val);
        if(root->left) preorderLeft(root->left, true);
        if(root->right) postorderRight(root->right, true);
        return ans;
    }

    void preorderLeft (TreeNode* root, bool isLeft) {
        if(isLeft || isLeaf(root)) ans.push_back(root->val);
        if(root->left) preorderLeft(root->left, isLeft);
        if (root->right) preorderLeft(root->right, isLeft && !root->left);

    }
    void postorderRight(TreeNode* root, bool isRight) {
        if(root->left) postorderRight(root->left, isRight && !root->right);
        if(root->right) postorderRight(root->right, isRight);
        if(isRight || isLeaf(root)) ans.push_back(root->val);
    }

    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
};
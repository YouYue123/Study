#include <bits/stdc++.h>
using namespace std;

// 776. Split BST [M]
// LeetCode split-bst

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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        if(!root) return { nullptr, nullptr };
        vector<TreeNode*> ans(2, nullptr);
        if(root->val <= target) {
            ans[0] = root;
            vector<TreeNode*> right = splitBST(root->right, target);
            root->right = right[0];
            ans[1] = right[1];
        } else {
            ans[1] = root;
            vector<TreeNode* > left = splitBST(root->left, target);
            root->left = left[1];
            ans[0] = left[0];
        }
        return ans;
    }
};
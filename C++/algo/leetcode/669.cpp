#include <bits/stdc++.h>
using namespace std;

// 669. Trim a Binary Search Tree [M]
// LeetCode trim-a-binary-search-tree

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
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INF);
        dummy->left = root;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur) {
            if(!cur) return;
            while(cur->left && (cur->left->val < low || cur->left->val > high)) {
                if(cur->left->val < low) {
                    cur->left = cur->left->right;
                } else if(cur->left->val > high) {
                    cur->left = cur->left->left;
                }
            }  
            while(cur->right && (cur->right->val < low || cur->right->val > high)) {
                if(cur->right->val < low) {
                    cur->right = cur->right->right;
                } else if(cur->right->val > high) {
                    cur->right = cur->right->left;
                }
            }
            dfs(cur->left);
            dfs(cur->right);
        };
        dfs(dummy);
        if(dummy->left && dummy->left->val >= low && dummy->left->val <= high) return dummy->left;
        if(dummy->right && dummy->right->val >= low && dummy->right->val <= high) return dummy->right;
        if(dummy->left) cout << dummy->left->val << endl;
        if(dummy->right) cout << dummy->right->val << endl;
        return nullptr;
    }
};
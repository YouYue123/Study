#include <bits/stdc++.h>
using namespace std;

// 105. Construct Binary Tree from Preorder and Inorder Traversal [M]
// LeetCode construct-binary-tree-from-preorder-and-inorder-traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i) {
            pos[inorder[i]] = i;
        }
        int preIdx = 0;
        auto dfs = [&](this auto&& dfs, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;
            int rootVal = preorder[preIdx];
            preIdx += 1;
            TreeNode* root = new TreeNode(rootVal);
            int mid = pos[rootVal];

            root->left = dfs(left, mid - 1);
            root->right = dfs(mid + 1, right);
            return root;
        };

        return dfs(0, n - 1);
    }
};
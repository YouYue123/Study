#include <bits/stdc++.h>
using namespace std;

// 1145. Binary Tree Coloring Game [M]
// LeetCode binary-tree-coloring-game

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
    int x;
    int leftCount;
    int rightCount;
    int dfs(TreeNode* root) {
        if(!root) return 0;
        int left = dfs(root->left), right = dfs(root->right);
        if(root->val == x) {
            leftCount = left;
            rightCount = right;
        }
        return left + right + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        this->x = x;
        dfs(root);
        return max({ leftCount, rightCount, n - leftCount - rightCount - 1 }) * 2 > n;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 366. Find Leaves of Binary Tree [M]
// LeetCode find-leaves-of-binary-tree

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
    vector<vector<int>> ans;
    int dfs(TreeNode* root) {
        if(!root) return -1;
        int leftHeight = dfs(root->left);
        int rightHeight = dfs(root->right);
        int curHeight = max(leftHeight, rightHeight) + 1;
        if(ans.size() == curHeight) ans.push_back({});
        ans[curHeight].push_back(root->val);
        return curHeight;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
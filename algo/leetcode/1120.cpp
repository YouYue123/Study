#include <bits/stdc++.h>
using namespace std;

// 1120. Maximum Average Subtree [M]
// LeetCode maximum-average-subtree

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
    double ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if(root == nullptr) return {0, 0};
        auto [leftSum, leftNodeCount] = dfs(root->left);
        auto [rightSum, rightNodeCount] = dfs(root->right);
        int cur = leftSum + rightSum + root->val;
        int curNodeCount = leftNodeCount + rightNodeCount + 1;
        ans = max(ans, double(cur) / curNodeCount);
        // cout << "root" << root->val << endl;
        // cout << "nodeCount" << curNodeCount << endl;
        return { cur, curNodeCount };
    }
    double maximumAverageSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
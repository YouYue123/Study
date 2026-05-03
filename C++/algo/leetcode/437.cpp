#include <bits/stdc++.h>
using namespace std;

// 437. Path Sum III [M]
// LeetCode path-sum-iii

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
    unordered_map<long long, long long> dict;
    int ans = 0;
    void dfs(TreeNode* root, int target, long long sum) {
        if(!root) return;
        sum += root->val;
        ans += dict[sum - target];
        dict[sum] += 1;
        dfs(root->left, target, sum);
        dfs(root->right, target, sum);
        dict[sum] -= 1;
    }
    int pathSum(TreeNode* root, int targetSum) {
        dict[0] = 1;
        dfs(root, targetSum, 0);
        return ans;
    }
};
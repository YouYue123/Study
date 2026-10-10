#include <bits/stdc++.h>
using namespace std;

// 1022. Sum of Root To Leaf Binary Numbers [E]
// LeetCode sum-of-root-to-leaf-binary-numbers

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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur, int num) {
            if(!cur) return;
            int nxtNum = num * 2 + cur->val;
            if(!cur->left && !cur->right) {
                ans += nxtNum;
                return;
            } else {
                dfs(cur->left, nxtNum);
                dfs(cur->right, nxtNum);
            }
        };
        dfs(root, 0);
        return ans;
    }
};
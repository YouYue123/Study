#include <bits/stdc++.h>
using namespace std;

// 652. Find Duplicate Subtrees [M]
// LeetCode find-duplicate-subtrees

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
    unordered_map<string, int> memo;
    vector<TreeNode*> ans;
public:
    string bt(TreeNode* root) {
        if(!root) return "$";
        string left = bt(root->left);
        string right = bt(root->right);
        string cur = to_string(root->val) + "," + left + "," + right;
        if(memo[cur] == 1) ans.push_back(root);
        memo[cur] += 1;
        return cur;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        bt(root);
        return ans;
    }
};
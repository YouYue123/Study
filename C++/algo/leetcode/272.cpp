#include <bits/stdc++.h>
using namespace std;

// 272. Closest Binary Search Tree Value II [H]
// LeetCode closest-binary-search-tree-value-ii

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
    priority_queue<pair<double, int>> pq;
    void dfs(TreeNode* root, double target, int k) {
        if(!root) return;
        pq.push({abs(root->val - target), root->val});
        if (pq.size() > k) pq.pop();
        dfs(root->left, target, k);
        dfs(root->right, target, k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root, target ,k);
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
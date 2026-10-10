#include <bits/stdc++.h>
using namespace std;

// 314. Binary Tree Vertical Order Traversal [M]
// LeetCode binary-tree-vertical-order-traversal

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
struct Node {
    TreeNode* node;
    int col;
};
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        int min_col = INF, max_col = -INF;
        unordered_map<int, vector<int>> dict;
        queue<Node> q;
        q.emplace(root, 0);
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i ++) {
                auto cur = q.front();
                q.pop();
                min_col = min(min_col, cur.col);
                max_col = max(max_col, cur.col);
                dict[cur.col].push_back(cur.node->val);
                if(cur.node->left) q.emplace(cur.node->left, cur.col - 1);
                if(cur.node->right) q.emplace(cur.node->right, cur.col + 1);
            }
        }
        vector<vector<int>> ans;
        for(int i = min_col; i <= max_col; i ++) {
            ans.push_back(dict[i]);
        }
        // for(auto& [idx, nodes] : dict) {
        //     ans.push_back(nodes);
        // }
        return ans;
    }
};
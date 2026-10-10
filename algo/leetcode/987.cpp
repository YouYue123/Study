#include <bits/stdc++.h>
using namespace std;

// 987. Vertical Order Traversal of a Binary Tree [H]
// LeetCode vertical-order-traversal-of-a-binary-tree

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
struct Item {
    int val;
    int row;
};
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, vector<Item>> dict;
        auto dfs = [&] (this auto&& dfs, TreeNode* cur, int row, int col) {
            if(!cur) return;
            dict[col].emplace_back(cur->val, row);
            if(cur->left) dfs(cur->left, row + 1, col - 1);
            if(cur->right) dfs(cur->right, row + 1, col + 1);
        };
        dfs(root, 0, 0);
        for(auto& [col, items] : dict) {
            sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
                if(a.row == b.row) return a.val < b.val;
                return a.row < b.row;
            });
            vector<int> tmp;
            for(auto& item : items) {
                tmp.push_back(item.val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
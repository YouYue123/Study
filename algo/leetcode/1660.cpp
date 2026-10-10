#include <bits/stdc++.h>
using namespace std;

// 1660. Correct a Binary Tree [M]
// LeetCode correct-a-binary-tree

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

// struct Node {
//     TreeNode* parent;
//     TreeNode* cur;
//     Node(TreeNode* _p, TreeNode* _c) : parent(_p), cur(_c) {};
//     Node(const Node& other) {
//         parent = other.parent;
//         cur = other.cur;
//     }
// };
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if(!root) return root;
        queue<pair<TreeNode*, TreeNode*>> q;
        q.push({ nullptr, root });
        while(!q.empty()) {
            int n = q.size();
            unordered_map<int, pair<TreeNode*, TreeNode*>> dict;
            for(int i = 0; i < n; i ++) {
                auto node = q.front();
                q.pop();
                TreeNode* cur = node.second;
                int val = cur->val;
                if(cur->left) q.push({ cur, cur->left });
                if(cur->right) {
                    // cout << node << endl;
                    dict[cur->right->val] = node;
                    q.push({ cur, cur->right });
                }
                if(dict.contains(val)) {
                    // cout << (dict[0].cur)->val << endl;
                    // cur->val;
                    auto toRemove = dict[val];
                    TreeNode* toRemoveTreeNode = toRemove.second;
                    TreeNode* parent = toRemove.first;
                    if(parent->left == toRemoveTreeNode) parent->left = nullptr;
                    if(parent->right == toRemoveTreeNode) parent->right = nullptr;
                    return root;
                }                
            }
        }
        return root;
        
    }
};
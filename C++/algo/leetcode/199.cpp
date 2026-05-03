// 199. Binary Tree Right Side View [M]
// LeetCode binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root) q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i ++) {
                auto* cur = q.front();
                if(i == n - 1) ans.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
            }
        }
        return ans;
    }
};
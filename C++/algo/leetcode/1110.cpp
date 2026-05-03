// 1110. Delete Nodes And Return Forest [M]
// LeetCode delete-nodes-and-return-forest

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, bool> dict;
    vector<TreeNode*> ans;
    void dfs(TreeNode* root) {
        if (!root) return;
        if (dict[root->val]) {
            // cout << "delete: " <<  root->val << endl;
            if (root->left && !dict[root->left->val]) {
                // cout << "adding left" << endl;
                ans.push_back(root->left);
            }
            if (root->right && !dict[root->right->val]) {
                // cout << "adding right" << endl;
                ans.push_back(root->right);
            }
        }
        dfs(root->left);
        if (root->left && dict[root->left->val])
            root->left = nullptr;
        dfs(root->right);
        if (root->right && dict[root->right->val])
            root->right = nullptr;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (!root)
            return {};
        for (int n : to_delete)
            dict[n] = true;
        if (!dict[root->val])
            ans.push_back(root);
        dfs(root);
        return ans;
    }
};
// 95. Unique Binary Search Trees II [M]
// LeetCode unique-binary-search-trees-ii

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
    vector<TreeNode*> bt(int left, int right) {
        vector<TreeNode*> ans;
        if(left > right) {
            ans.emplace_back(nullptr);
            return ans;
        }
        for(int i = left; i <= right; i ++) {
            vector<TreeNode*> leftTrees = bt(left, i - 1);
            vector<TreeNode*> rightTrees = bt(i + 1, right);
            for(auto left : leftTrees) {
                for(auto right: rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.emplace_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return bt(1, n);
    }
};
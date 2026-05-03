// 2196. Create Binary Tree From Descriptions [M]
// LeetCode create-binary-tree-from-descriptions

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> dict;
        unordered_set<int> children;
        for(auto& description : descriptions) {
            int parent = description[0], child = description[1], is_left = description[2];
            if(!dict.contains(parent)) dict[parent] = new TreeNode(parent);
            if(!dict.contains(child)) dict[child] = new TreeNode(child);
            children.insert(child);
            if(is_left) {
                dict[parent]->left = dict[child];
            } else {
                dict[parent]->right = dict[child];
            }
        }
        for(auto& [val, node] : dict) {
            if(!children.contains(val)) return node;
        }
        return nullptr;
    }
};
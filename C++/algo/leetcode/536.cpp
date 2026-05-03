// 536. Construct Binary Tree from String [M]
// LeetCode construct-binary-tree-from-string

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
    TreeNode* str2tree(string s) {
        int n = s.size();
        if(s.empty()) return nullptr;
        
        int i = 0;
        auto dfs = [&] (this auto&& dfs) -> TreeNode* {
            if(i == n) return nullptr;
            int start = i;
            if(s[i] == '-') {
                i += 1;
            }
            while(i < n && isdigit(s[i])) i += 1;
            int curVal = stoi(s.substr(start, i - start));
            TreeNode* curNode = new TreeNode(curVal);
            if(i < n && s[i] == '(') {
                i += 1;
                curNode->left = dfs();
                i += 1;
            }
            if(i < n && s[i] == '(') {
                i += 1;
                curNode->right = dfs();
                i += 1;
            }
            return curNode;
        };
        return dfs();
    }
};
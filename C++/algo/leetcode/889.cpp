#include <bits/stdc++.h>
using namespace std;

// 889. Construct Binary Tree from Preorder and Postorder Traversal [M]
// LeetCode construct-binary-tree-from-preorder-and-postorder-traversal

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
typedef vector<int>::iterator it;
class Solution {
public:
    TreeNode* bt(it preStart, it preEnd, it postStart, it postEnd) {
        if(preStart == preEnd) return nullptr;
        TreeNode* root = new TreeNode(*preStart);
        if(preStart + 1 == preEnd) return root;
        it postPos = find(postStart, postEnd, *(preStart + 1));
        int leftCount = postPos - postStart + 1;
        root->left = bt(preStart + 1, preStart + leftCount + 1, postStart, postPos);
        root->right = bt(preStart + leftCount + 1, preEnd, postPos + 1, postEnd);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return bt(preorder.begin(), preorder.end(), postorder.begin(), postorder.end());
    }
};
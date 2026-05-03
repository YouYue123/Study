#include <bits/stdc++.h>
using namespace std;

// 106. Construct Binary Tree from Inorder and Postorder Traversal [M]
// LeetCode construct-binary-tree-from-inorder-and-postorder-traversal

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
    TreeNode* dfs(
        vector<int>& inorder, int inStart, int inEnd,
        vector<int>& postorder, int posStart, int posEnd
    ) {
        if(inStart >= inEnd || posStart >= posEnd ) return nullptr;
        int cur = postorder[posEnd - 1];
        int inPos = inStart;
        // cout << "========" << endl;
        // cout << inStart << " " << inEnd << endl;
        // cout << posStart << " " << posEnd << endl;
        while(inorder[inPos] != cur) inPos += 1;
        // cout << inPos << endl;
        int leftCnt = inPos - inStart;
        TreeNode* root = new TreeNode(cur);
        root->left = dfs(
            inorder, inStart, inStart + leftCnt,
            postorder, posStart, posStart + leftCnt
        );
        root->right = dfs(
            inorder, inStart + leftCnt + 1, inEnd,
            postorder, posStart + leftCnt, posEnd - 1
        );
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return dfs(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};
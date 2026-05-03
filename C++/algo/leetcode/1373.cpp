#include <bits/stdc++.h>
using namespace std;

// 1373. Maximum Sum BST in Binary Tree [H]
// LeetCode maximum-sum-bst-in-binary-tree

class DS {
public:
    int sum;
    bool isBST;
    int maxVal;
    int minVal;
    DS(int sum, bool isBST, int minVal, int maxVal) : sum(sum), isBST(isBST), minVal(minVal), maxVal(maxVal) {}
};

class Solution {
public:
    int ans;

    DS helper(TreeNode* root) {
        if (!root) return DS(0, true, INT_MAX, INT_MIN);
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        bool isBST = left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal;
        int sum = 0;
        if (isBST) {
            sum = left.sum + right.sum + root->val;
            ans = max(ans, sum);
        }
        
        int currentMin = min(root->val, min(left.minVal, right.minVal));
        int currentMax = max(root->val, max(left.maxVal, right.maxVal));
        
        return DS(sum, isBST, currentMin, currentMax);
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};
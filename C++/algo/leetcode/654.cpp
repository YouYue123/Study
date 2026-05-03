// 654. Maximum Binary Tree [M]
// LeetCode maximum-binary-tree

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
    TreeNode* bt(vector<int>& nums, int start, int end) {
        if(start > end) return nullptr;
        int maxPos = start;
        for(int i = start; i <= end; i ++) {
            if(nums[i] > nums[maxPos]) maxPos = i;
        }
        TreeNode* ans = new TreeNode(nums[maxPos]);
        ans->left = bt(nums, start, maxPos - 1);
        ans->right = bt(nums, maxPos + 1, end);
        return ans;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return bt(nums, 0, nums.size() - 1);
    }
};
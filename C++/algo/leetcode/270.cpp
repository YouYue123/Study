// 270. Closest Binary Search Tree Value [E]
// LeetCode closest-binary-search-tree-value

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
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:

    int closestValue(TreeNode* root, double target) {
        if(!root) return INF;
        int temp = root->val;
        if (target < root->val) {
            int leftClosest = closestValue(root->left, target);
            if(abs(leftClosest - target) < abs(temp - target)) {
                return leftClosest;    
            } else if(abs(leftClosest - target) == abs(temp - target)) {
                return min(leftClosest, temp);
            }
        } else if(target == root->val) {
            return root->val;
        } else if(target > root->val) {
            int rightClosest = closestValue(root->right, target);
            if(abs(rightClosest - target) < abs(temp - target)) {
                return rightClosest;    
            } else if (abs(rightClosest - target) == abs(temp - target)) { 
                return min(rightClosest, temp);
            }
        }
        return temp;
    }
};
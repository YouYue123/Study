// 572. Subtree of Another Tree [E]
// LeetCode subtree-of-another-tree

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
    bool isSame(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        if(t1->val == t2->val) {
            return isSame(t1->left, t2->left) && isSame(t1->right, t2->right);
        } else {
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false;
        if(isSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
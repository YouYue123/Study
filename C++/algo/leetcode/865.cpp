// 865. Smallest Subtree with all the Deepest Nodes [M]
// LeetCode smallest-subtree-with-all-the-deepest-nodes

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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        TreeNode* ans;
        int maxDepth = 0;
        auto dfs = [&] (this auto&& dfs, TreeNode* r, int depth) {
            if(!r) {
                maxDepth = max(maxDepth, depth);
                return depth;
            }
            int leftMaxDepth = dfs(r->left, depth + 1);
            int rightMaxDepth = dfs(r->right, depth + 1);
            if(leftMaxDepth == maxDepth && rightMaxDepth == maxDepth) {
                ans = r;
            }
            return max(leftMaxDepth, rightMaxDepth);
        };
        dfs(root, 0);
        return ans;
    }
};
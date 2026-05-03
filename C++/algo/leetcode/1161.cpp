// 1161. Maximum Level Sum of a Binary Tree [M]
// LeetCode maximum-level-sum-of-a-binary-tree

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
    int maxLevelSum(TreeNode* root) {
        int ans = INF;
        int curMax = -INF;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int n = q.size();
            level += 1;
            int sum = 0;
            for(int i = 0; i < n; i ++) {
                TreeNode* t = q.front();
                q.pop();
                sum += t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right); 
            }
            if(sum > curMax) {
                curMax = sum;
                ans = level;
            }
        }
        return ans;
    }
};
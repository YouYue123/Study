// 2471. Minimum Number of Operations to Sort a Binary Tree by Level [M]
// LeetCode minimum-number-of-operations-to-sort-a-binary-tree-by-level

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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            vector<int> original;
            for(int i = 0; i < n; i ++) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                original.push_back(cur->val);
            }
            vector<int> sorted = original;
            sort(sorted.begin(), sorted.end());
            vector<bool> visited(n, false);
            for(int i = 0; i < n; i ++) {
                if(visited[i] || sorted[i] == original[i]) continue;
                int cycleSize = 0;
                int j = i;
                while(!visited[j]) {
                    visited[j] = true;
                    auto it = lower_bound(sorted.begin(), sorted.end(), original[j]);
                    j = distance(sorted.begin(), it);
                    cycleSize += 1;
                }
                ans += cycleSize - 1;
            }
        }
        return ans;
    }
};
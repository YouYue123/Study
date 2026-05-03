// 863. All Nodes Distance K in Binary Tree [M]
// LeetCode all-nodes-distance-k-in-binary-tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        auto set_parent = [&] (this auto&& dfs, TreeNode* cur, TreeNode* p) {
            if(!cur) return;
            parent[cur->val] = p;
            dfs(cur->left, cur);
            dfs(cur->right, cur);
        };  
        set_parent(root, nullptr);
        queue<TreeNode*> q;
        unordered_set<TreeNode*> visited;
        int dist = 0;
        q.push(target);
        visited.insert(target);
        vector<int> ans;
        // cout << parent[5] << endl;
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i ++) {
                auto* cur = q.front();
                q.pop();
                if(dist == k) {
                    ans.push_back(cur->val);
                    continue;
                } 
                if(cur->left && !visited.contains(cur->left)) {
                    q.push(cur->left);
                    visited.insert(cur->left);
                }
                if(cur->right && !visited.contains(cur->right)) {
                    q.push(cur->right);
                    visited.insert(cur->right);
                }
                if(parent[cur->val] && !visited.contains(parent[cur->val])) {
                    // cout << parent[cur->val]->val << endl;
                    q.push(parent[cur->val]);
                    visited.insert(parent[cur->val]);
                }
            }
            dist += 1;
        }
        return ans;
    }
};
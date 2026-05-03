// 1382. Balance a Binary Search Tree [M]
// LeetCode balance-a-binary-search-tree

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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nums;
        auto dfs = [&] (this auto&& dfs, TreeNode* root) {
            if(root == nullptr) return;
            dfs(root->left);
            nums.push_back(root);
            dfs(root->right);
        };
        dfs(root);
        int n = nums.size();
        // for(int num : nums) cout << num << " ";
        auto construct = [&] (this auto&& dfs, int left, int right) -> TreeNode* {
            if(left > right) return nullptr;
            if(left == right) {
                nums[left]->left = nullptr;
                nums[right]->right = nullptr;
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            auto root = nums[mid];
            root->left = dfs(left, mid - 1);
            root->right = dfs(mid + 1, right);
            return root;
        };
        
        return construct(0, n - 1);
    }
};
#include <bits/stdc++.h>
using namespace std;

// 337. House Robber III [M]
// LeetCode house-robber-iii

class Solution {
public: 
unordered_map<TreeNode*, int> dp; // Memoization map using root of the tree 

int possible(TreeNode* root){
    if(root == NULL) return 0;
    if(dp.find(root) != dp.end()) return dp[root];
     
     int rob1 = root->val;
     if(root->left){
        rob1 +=  possible(root->left->left);
        rob1 += possible(root->left->right);
     }

     if(root->right){
        rob1 += possible(root->right->left);
        rob1 += possible(root->right->right);
     }


     int rob2 = possible(root->left) + possible(root->right); // directly add the chldren 

     return dp[root] = max(rob1 , rob2);
}
    int rob(TreeNode* root) {
        if(root == NULL) return NULL; // if root is null
        if(root->left == NULL && root->right ==  NULL) return root->val; //if there is only one element

      return  possible(root);
        
    }
};
#include <bits/stdc++.h>
using namespace std;

// 255. Verify Preorder Sequence in Binary Search Tree [M]
// LeetCode verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        // stack<int> s;
        int i = 0;
        for(auto num : preorder) {
            while(i > 0 && preorder[i - 1] < num) {
                minLimit = preorder[i - 1];
                i --;
            }
            if(minLimit >= num) return false;
            preorder[i] = num;
            i += 1;
            // s.push(num);
        }
        return true;   
    }
};
#include <bits/stdc++.h>
using namespace std;

// 1111. Maximum Nesting Depth of Two Valid Parentheses Strings [M]
// LeetCode maximum-nesting-depth-of-two-valid-parentheses-strings

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int leftCnt = 0;

        vector<int> ans;
        for(int i = 0 ; i < seq.size(); i ++) {
            char c = seq[i];
            if(c == '(') {
                leftCnt += 1;
                ans.push_back(leftCnt % 2);
            } else {
                ans.push_back(leftCnt % 2);
                leftCnt -= 1;
            }
        }
        return ans;
    }
};
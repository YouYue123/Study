#include <bits/stdc++.h>
using namespace std;

// 135. Candy [H]
// LeetCode candy

class Solution {
public:
    int candy(vector<int>& ratings) {
        int m = ratings.size();
        vector<int> leftMax(ratings.size(), 1);
        vector<int> rightMax(ratings.size(), 1);
        for(int i = 1; i < m; i ++) {
            if(ratings[i] > ratings[i - 1]) leftMax[i] = leftMax[i - 1] + 1;
        }
        for(int i = m - 2; i >=0; i --) {
            if(ratings[i] > ratings[i + 1]) rightMax[i] = rightMax[i + 1] + 1;
        }
        int ans = 0;
        for(int i = 0; i < m; i ++) {
            ans += max(leftMax[i], rightMax[i]);
        }
        return ans;
    }
};
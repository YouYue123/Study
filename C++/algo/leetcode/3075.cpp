#include <bits/stdc++.h>
using namespace std;

// 3075. Maximize Happiness of Selected Children [M]
// LeetCode maximize-happiness-of-selected-children

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<>());
        int p = 0;
        long long ans = 0;
        for(int i = 0; i < k; i ++) {
            int h = happiness[i];
            if(h <= p) break;
            ans += h - p;
            p += 1;
        }
        return ans;
    }
};
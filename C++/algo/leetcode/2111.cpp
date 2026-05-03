#include <bits/stdc++.h>
using namespace std;

// 2111. Minimum Operations to Make the Array K-Increasing [H]
// LeetCode minimum-operations-to-make-the-array-k-increasing

class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        int ans = 0;
        for(int i = 0; i < k; i ++) {
            vector<int> g;
            int cnt = 0;
            for(int j = i; j < arr.size(); j += k) {
                cnt += 1;
                auto idx = upper_bound(g.begin(), g.end(), arr[j]) - g.begin();
                if(idx == g.size()) {
                    g.push_back(arr[j]);
                } else {
                    g[idx] = arr[j];
                }
            }
            ans += cnt - g.size();
        }
        return ans;
    }
};
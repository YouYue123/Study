#include <bits/stdc++.h>
using namespace std;

// 673. Number of Longest Increasing Subsequence [M]
// LeetCode number-of-longest-increasing-subsequence

class Solution {
    int binarySearch(int n, function<bool(int)> f) {
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<int>> d, cnt;
        for (int v : nums) {
            // Find the position in d where we should place v
            int i = binarySearch(d.size(), [&](int i) { 
                return d[i].back() >= v; 
            });
            
            int c = 1;
            if (i > 0) {
                // Find the first position in previous level where value < v
                int k = binarySearch(d[i-1].size(), [&](int k) { 
                    return d[i-1][k] < v; 
                });
                // Calculate count from cnt array
                c = cnt[i-1].back() - (k > 0 ? cnt[i-1][k-1] : 0);
            }
            
            if (i == d.size()) {
                d.push_back({v});
                cnt.push_back({c});
            } else {
                d[i].push_back(v);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        
        return cnt.empty() ? 0 : cnt.back().back();
    }
};
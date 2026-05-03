#include <bits/stdc++.h>
using namespace std;

// 3269. Constructing Two Increasing Arrays [H]
// LeetCode constructing-two-increasing-arrays

static constexpr long long INF = 0x3f3f3f3f;
class Solution {
public:
    int minLargest(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        auto getNext = [&] (int prev, int parity) {
            int nxt = prev + 1;
            return (nxt % 2 == parity) ? nxt : nxt + 1;
        };
        int size = (m + 1) * (n + 1);
        vector<int> memo(size);
        memset(memo.data(), 0x3f, size * sizeof(int));        
        auto dfs = [&] (this auto&& dfs, int i, int j) {
            if(i == 0 && j == 0) return 0;
            if(memo[i * (n + 1) + j] != 0x3f3f3f3f) return memo[i * (n + 1) + j] ;
            int ans = INF;
            if(i > 0) {
                int preVal = dfs(i - 1, j);
                ans = min(ans, getNext(preVal, nums1[i - 1]));
            }
            if(j > 0) {
                int preVal = dfs(i, j - 1);
                ans = min(ans, getNext(preVal, nums2[j - 1]));
            }
            return memo[i * (n + 1) + j] = ans;
        };
        return dfs(m, n);
    }
};
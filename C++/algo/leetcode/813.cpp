#include <bits/stdc++.h>
using namespace std;

// 813. Largest Sum of Averages [M]
// LeetCode largest-sum-of-averages

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(n, vector(k + 1, -1.0));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt > k) return DBL_MIN;
            if(i == n) return 0.0;
            if(memo[i][cnt] != -1.0) return memo[i][cnt];
            double sum = 0;
            double ans = DBL_MIN;
            for(int j = i; j < n; j ++) {
                sum += nums[j];
                double score = sum / ( j - i + 1);
                double remain = dfs(j + 1, cnt + 1);
                // cout << i << " " << j << " " << remain << " " << score << endl;
                if(remain != DBL_MIN) ans = max(ans, remain + score);
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};
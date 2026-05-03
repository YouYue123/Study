#include <bits/stdc++.h>
using namespace std;

// 1074. Number of Submatrices That Sum to Target [H]
// LeetCode number-of-submatrices-that-sum-to-target

class Solution {
public:
    int calc(vector<int>& nums, int target) {
        int ans = 0;
        unordered_map<int, int> dict;
        dict[0] = 1;
        long long sum = 0;
        for(int num : nums) {
            sum += num;
            ans += dict.contains(sum - target) ? dict[sum - target] : 0;
            dict[sum] += 1;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; ++i) {
            vector<int> colSum(n);
            for(int i2 = i; i2 < m; ++i2) {
                for(int j = 0; j < n; ++j) {
                    colSum[j] += matrix[i2][j];
                }
                ans += calc(colSum, target);
            }
        }
        return ans;
    }
};
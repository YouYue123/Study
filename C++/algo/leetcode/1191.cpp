#include <bits/stdc++.h>
using namespace std;

// 1191. K-Concatenation Maximum Sum [M]
// LeetCode k-concatenation-maximum-sum

int MOD = 1e9 + 7;
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long ans = 0;
        long long curSum = 0;
        long long totalSum = 0;
        for(int i = 0; i < arr.size(); i ++) {
            curSum = max((long long)arr[i], ((long long)arr[i] + curSum) % MOD);
            ans = max(ans, curSum);   
            totalSum += arr[i];
        }
        if(k >= 2) {
            if(totalSum > 0) curSum = (curSum + totalSum * (k - 2));
            for(int i = 0; i < arr.size(); i ++) {
                curSum = max((long long)arr[i], ((long long)arr[i] + curSum));
                ans = max(ans, curSum);
            }
        }
        return ans % MOD;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 1524. Number of Sub-arrays With Odd Sum [M]
// LeetCode number-of-sub-arrays-with-odd-sum

int MOD = 1e9 + 7;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        // even - odd = odd
        // odd - even = odd
        int sum = 0;
        vector<int> dict(2, 0);
        dict[0] = 1;
        long long ans = 0;
        for(int num : arr) {
            sum += num;
            if(sum % 2 == 0) {
                ans = (ans + dict[1]) % MOD; 
            } else {
                ans = (ans + dict[0]) % MOD;
            }
            dict[sum % 2] += 1;
        }
        return ans;
    }
};
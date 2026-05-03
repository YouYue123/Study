#include <bits/stdc++.h>
using namespace std;

// 1818. Minimum Absolute Sum Difference [M]
// LeetCode minimum-absolute-sum-difference

int MOD = 1e9 + 7;
int modPlus(int a, int b, int mod = MOD)
{
    return ((long long)(a) + b) % mod;
}

int modMinus(int a, int b, int mod = MOD)
{
    return (((long long)(a)-b) + mod) % mod;
}

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> origin;
        for(int i = 0; i < n; i ++) origin.push_back(abs(nums1[i] - nums2[i]));
        sort(nums1.begin(), nums1.end());
        int ans = 0;
        int maxGain = 0;
        for(int i = 0; i < n; i ++) {
            int num2 = nums2[i];
            auto it1 = lower_bound(nums1.begin(), nums1.end(), num2);
            int diff1 = it1!= nums1.end() ? abs(*it1 - num2) : INT_MAX;
            int diff2 = it1 != nums1.begin() ? abs(*prev(it1) - num2) : INT_MAX;
            maxGain = max(maxGain, origin[i] - min(diff1, diff2));
        }
        for(int i = 0; i < n; i ++) {
            ans = modPlus(ans, origin[i]);
        }
        // cout << ans << endl;
        // cout << maxGain << endl;
        ans = modMinus(ans, maxGain);
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 3299. Sum of Consecutive Subsequences [H]
// LeetCode sum-of-consecutive-subsequences

int MOD = 1e9 + 7;
class Solution {
public:
    int getSum(vector<int>& nums) {
        int n = nums.size();
        using pii = pair<long long, long long>;
        // num -> { sum, cnt }
        unordered_map<int, pii> hDict;
        unordered_map<int, pii> lDict;
        long long ans = 0;
        for(int num : nums) {
            int ht = num + 1, lt = num - 1;
            long long cnt = lDict[lt].second + 1;
            long long totalContrib = 0;
            long long contrib = (lDict[lt].first + (cnt * num) % MOD) % MOD;
            lDict[num].first = (lDict[num].first + contrib) % MOD;
            lDict[num].second = lDict[num].second  + cnt;
            totalContrib = (totalContrib + contrib) % MOD;
            // cout << "lContrib: " << contrib << endl;
            cnt = hDict[ht].second + 1;
            contrib = (hDict[ht].first + (cnt * num) % MOD) % MOD;
            hDict[num].first = hDict[num].first + contrib;
            hDict[num].second = (hDict[num].second  + cnt) % MOD;
            // cout << "hContrib: " << contrib << endl;
            totalContrib = ((totalContrib + contrib) % MOD - num + MOD) % MOD;
            // cout << totalContrib << endl;
            ans = (ans + totalContrib) % MOD;
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 1537. Get the Maximum Score [H]
// LeetCode get-the-maximum-score

int MOD = 1e9 + 7;
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict1, dict2;
        for(int i = 0; i < nums1.size(); i ++) dict1[nums1[i]] = i;
        for(int i = 0; i < nums2.size(); i ++) dict2[nums2[i]] = i;
        vector memo(
            max(nums1.size(), nums2.size()),
            vector(2, -1LL)
        );
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long {
            if(state == 0 && i == nums1.size()) return 0;
            if(state == 1 && i == nums2.size()) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = 0;
            if(state == 0) {
                int num = nums1[i];
                ans = (dfs(i + 1, 0) + num);
                if(dict2.contains(num)) ans = max(ans, dfs(dict2[num] + 1, 1) + num);
            } else {
                int num = nums2[i];
                ans = dfs(i + 1, 1) + num;
                // cout << num << " " << dict1.contains(num) << endl;
                if(dict1.contains(num)) ans = max(ans, dfs(dict1[num] + 1, 0) + num);
            }
            return memo[i][state] = ans;
        };
        // dfs(0 , 0);
        // dfs(0, 1);
        // for(int i = 0; i <  max(nums1.size(), nums2.size()); i ++) {
        //     cout << memo[i][0] << " " << memo[i][1] << endl;
        // }
        return max(dfs(0, 0), dfs(0, 1)) % MOD;
    }
};
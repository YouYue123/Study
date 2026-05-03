#include <bits/stdc++.h>
using namespace std;

// 2369. Check if There is a Valid Partition For The Array [M]
// LeetCode check-if-there-is-a-valid-partition-for-the-array

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) -> bool{
            // cout << i << endl;
            if(i == n) return true;
            if(memo[i] != -1) return memo[i];
            bool ans = false;
            if(i + 1 < n && nums[i + 1] == nums[i]) ans = dfs(i + 2);
            if(i + 2 < n) {
                if(nums[i + 1] == nums[i] && nums[i + 2] == nums[i]) ans = ans || dfs(i + 3);
                if(nums[i + 1] == (nums[i] + 1) && nums[i + 2] == (nums[i] + 2)) ans = ans || dfs(i + 3);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};
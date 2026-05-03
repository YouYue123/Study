// 3524. Find X Value of Array I [M]
// LeetCode find-x-value-of-array-i

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(n, vector(k, -1LL));
        auto dfs = [&] (this auto&& dfs, int i, int rem) -> long long {
            if(i < 0) return 0;
            if(memo[i][rem] != -1) return memo[i][rem];
            long long ans = 0;
            if(nums[i] % k == rem) ans += 1;
            for(int preRem = 0; preRem < k; preRem += 1) {
                if((1LL * preRem * nums[i]) % k == rem) ans += dfs(i - 1, preRem);
            }
            return memo[i][rem] = ans;
        };
        vector<long long> ans;
        for(int x = 0; x < k; x ++) {
            long long sum = 0;
            for(int i = 0; i < n; i ++) {
                sum += dfs(i, x);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
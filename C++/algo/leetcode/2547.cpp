// 2547. Minimum Cost to Split an Array [H]
// LeetCode minimum-cost-to-split-an-array

class Solution {
public:
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(n, -1);
        auto dfs = [&](this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            unordered_map<int, int> freq;
            int cnt = 0;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                int num = nums[j];
                freq[num] += 1;
                if(freq[num] == 2) cnt += 2; 
                else if(freq[num] > 2) cnt += 1;
                ans = min(
                    ans,
                    k + cnt + dfs(j + 1)
                );
            }
            return memo[i] = ans;
        };
        // dfs(0);
        // for(int item : memo) cout << item << " ";
        // cout << endl;
        return dfs(0);
    }
};
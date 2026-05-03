// 2597. The Number of Beautiful Subsets [M]
// LeetCode the-number-of-beautiful-subsets

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, map<int, int>> dict;
        for(int num : nums) {
            dict[num % k][num] += 1;
        }
        int ans = 1;
        for(auto& [num, freqMap] : dict) {
            int n = freqMap.size();
            vector<pair<int, int>> curNums(freqMap.begin(), freqMap.end()); 
            // for(auto& item : curNums) cout << item.first << " " << item.second << endl;
            vector memo(n, -1);
            auto dfs = [&] (this auto&& dfs, int i) -> int {
                if(i == n) return 1;
                if(memo[i] != -1) return memo[i];
                int ans = dfs(i + 1);
                int choose = (1 << curNums[i].second) - 1;
                if(i + 1 < n && curNums[i].first + k == curNums[i + 1].first) {
                    ans += choose * dfs(i + 2);
                } else {
                    ans += choose * dfs(i + 1);
                }
                // cout << "i: " << i << endl;
                // cout << ans << endl;
                return memo[i] = ans;
            };
            ans *= dfs(0);
        }
        return ans - 1;
    }
};
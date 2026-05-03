// 3180. Maximum Total Reward Using Operations I [M]
// LeetCode maximum-total-reward-using-operations-i

class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        vector memo(
            n,
            vector(2001, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int reward) {
            if(i >= n || reward > 2000) return reward;
            if(memo[i][reward] != -1) return memo[i][reward];
            int ans = dfs(i + 1, reward);
            if(reward < rewardValues[i]) ans = max(ans, dfs(i + 1, reward + rewardValues[i]));
            return memo[i][reward] = ans;
        };

        return dfs(0, 0);
    }
};
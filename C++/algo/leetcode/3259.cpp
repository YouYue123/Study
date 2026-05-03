// 3259. Maximum Energy Boost From Two Drinks [M]
// LeetCode maximum-energy-boost-from-two-drinks

class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n = energyDrinkA.size();
        vector memo(
            n,
            vector(2, -1LL)
        );
        auto dfs = [&] (this auto&& dfs, int i, int state) -> long long {
            if (i == n) return 0;
            if(memo[i][state] != -1) return memo[i][state];
            long long ans = 0;
            if(state == 0) {
                ans = max(dfs(i + 1, 1), energyDrinkA[i] + dfs(i + 1, 0));
            } else {
                ans = max(dfs(i + 1, 0), energyDrinkB[i] + dfs(i + 1, 1));
            } 
            return memo[i][state] = ans;
        };
        return max(dfs(0, 0), dfs(0, 1));
    }
};
// 403. Frog Jump [H]
// LeetCode frog-jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] != 1) return false;
        vector memo(n, vector(n, -1));
        auto dfs = [&] (this auto&& dfs, int i, int lastIdx) {
            if(i == n - 1) return true;
            if(memo[i][lastIdx] != -1) return memo[i][lastIdx] == 1;
            int lastJump = stones[i] - stones[lastIdx];
            bool ans = false;
            for(int j = i + 1; j < n; j ++) {
                int nxtJump = stones[j] - stones[i];
                if(abs(nxtJump - lastJump) <= 1) ans |= dfs(j, i);
                if(ans || nxtJump > lastJump + 1) break;
            }
            memo[i][lastIdx] = (ans ? 1 : 0);
            return ans;
        };

        return dfs(1, 0);
    }
};
// 3147. Taking Maximum Energy From the Mystic Dungeon [M]
// LeetCode taking-maximum-energy-from-the-mystic-dungeon

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector memo(n, vector(2, -INF));
        auto dfs = [&](this auto&& dfs, int i, int state) -> int {
            if(i >= n) return state == 0 ? -INF : 0;
            if(memo[i][state] != -INF) return memo[i][state];
            int ans = 0;
            if(state == 0) {
                ans = max(
                    dfs(i + 1, 0),
                    energy[i] + dfs(i + k, 1)
                );
            } else if (state == 1){
                ans = energy[i] + dfs(i + k, 1);
            }
            return memo[i][state] = ans;
        };
        return dfs(0, 0);
    }
};
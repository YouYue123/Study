// 2266. Count Number of Texts [M]
// LeetCode count-number-of-texts

int MOD = 1e9 + 7;
class Solution {
public:
    int countTexts(string pressedKeys) {
        int maxCnt = 3;
        int n = pressedKeys.size();
        vector<vector<int>> memo(
            2,
            vector<int>(1e5 + 1, -1)
        );
        auto dfs = [&] (this auto&& dfs, int i, int k, int end) {
            if(i == end) return 1;
            int key1 = k % 3;
            int key2 = end - i;
            if(memo[key1][key2] != -1) return memo[key1][key2];
            long long ans = 0;
            for(int d = 1; d <= k; d ++) {
                int ni = i + d;
                if(ni <= end) ans = (ans + dfs(ni, k, end)) % MOD;
            }
            return memo[key1][key2] = ans;
        };
        int left = 0, right = 0;
        int ans = 1;
        while(right <= n) {
            int k = (pressedKeys[left] == '7' || pressedKeys[left] == '9') ? 4 : 3;
            if(right == n || pressedKeys[right] != pressedKeys[left]) {
                // cout << left << " " << right << endl;
                // cout << dfs(left, k, right) << endl;
                ans = ((long long)ans * dfs(left, k, right)) % MOD;
                left = right;
            }
            right += 1;
        }

        return ans;
    }
};
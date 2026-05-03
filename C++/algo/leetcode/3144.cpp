// 3144. Minimum Substring Partition of Equal Character Frequency [M]
// LeetCode minimum-substring-partition-of-equal-character-frequency

class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector memo(n, -1);
        auto dfs = [&] (this auto&& dfs, int i) {
            if(i == n) return 0;
            if(memo[i] != -1) return memo[i];
            int ans = INT_MAX;
            vector<int> cnt(26, 0);
            for(int j = i; j < n; j ++) {
                cnt[s[j] - 'a'] += 1;
                bool isValid = true;
                for(int freq : cnt) {
                    if(freq != 0 && freq != cnt[s[j] - 'a']) {
                        isValid = false;
                        break;
                    }
                }
                if(isValid) ans = min(ans, dfs(j + 1) + 1);
            }
            return memo[i] = ans;
        };
        return dfs(0);
    }
};
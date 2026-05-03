// 3389. Minimum Operations to Make Character Frequencies Equal [H]
// LeetCode minimum-operations-to-make-character-frequencies-equal

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int makeStringGood(string s) {
        int freq[26];
        int maxFreq = 0;
        for(char c : s) {
            freq[c - 'a'] += 1;
            if(freq[c - 'a'] > maxFreq) maxFreq = freq[c - 'a'];
        }
        int ans = INF;
        int memo[26];
        for(int f = 1; f <= maxFreq; f ++) {
            memset(memo, -1, sizeof(memo));
            auto dfs = [&](this auto&& dfs, int i) {
                if(i > 25) return 0;
                int x = freq[i];
                if(memo[i] != -1) return memo[i];
                if(x == 0) return dfs(i + 1);
                if(i == 25) return min(x, abs(f - x));
                int ans = INF;
                if(x == f) {
                    ans = dfs(i + 1);
                } else {
                    if(i < 25 && freq[i + 1] < f) { // change to next
                        ans = dfs(i + 2);
                        if(x > f) {
                            ans += max(x - f,f - freq[i + 1]);
                        } else {
                            ans += max(x,  f - freq[i + 1]);
                        }
                    }
                    ans = min(
                        ans, 
                        dfs(i + 1) + min(x, abs(f - x)) // delete or insert
                    ); 
                }
                return memo[i] = ans;
            };
            // cout << f << " " << dfs(0) << endl;
            ans = min(ans, dfs(0));
        }
        return ans;
    }
};
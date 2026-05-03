// 1542. Find Longest Awesome Substring [H]
// LeetCode find-longest-awesome-substring

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int val = 0;
        unordered_map<int, int> cnt;
        cnt[0] = -1;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            val ^= (1 << (s[i] - '0'));
            if(cnt.contains(val)) {
                ans = max(ans, i - cnt[val]);
            }
            for(int j = 0; j <= 9; j ++) {
                int t = val ^ (1 << j);
                if(cnt.contains(t)) {
                    ans = max(ans, i - cnt[t]);
                }
            }
            if(!cnt.contains(val)) cnt[val] = i;
        }
        return ans;
    }
};
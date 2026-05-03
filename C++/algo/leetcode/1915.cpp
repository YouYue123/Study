// 1915. Number of Wonderful Substrings [M]
// LeetCode number-of-wonderful-substrings

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int n = word.size();
        int val = 0;
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        long long ans = 0;
        for(char c : word) {
            val ^= (1 << (c - 'a'));
            ans += cnt.contains(val) ? cnt[val] : 0;
            for(int i = 0 ; i < 26; i ++) {
                int t = val ^ (1 << i);
                ans += cnt.contains(t) ? cnt[t] : 0;
            }
            cnt[val] += 1;
        }
        return ans;
    }
};
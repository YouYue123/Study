// 1371. Find the Longest Substring Containing Vowels in Even Counts [M]
// LeetCode find-the-longest-substring-containing-vowels-in-even-counts

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> dict = {
            {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}
        };
        unordered_map<int, int> cnt;
        cnt[0] = -1;
        int val = 0;
        int ans = 0;
        for(int i = 0; i < n; i ++) {
            if(dict.contains(s[i])) {
                val ^= (1 << dict[s[i]]);
            }
            if(cnt.contains(val)) {
                ans = max(ans, i - cnt[val]);
            } else {
                cnt[val] = i;
            }
        }
        return ans;
    }
};
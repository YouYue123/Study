// 1016. Binary String With Substrings Representing 1 To N [M]
// LeetCode binary-string-with-substrings-representing-1-to-n

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> seen;
        int m = s.size();
        for(int i = 0; i < m; ++i) {
            int x = s[i] - '0';
            if(x == 0) continue;
            for(int j = i + 1; x <= n; j ++) {
                seen.insert(x);
                if(j == m) break;
                x = (x << 1) | (s[j] - '0');
            }
        }
        return seen.size() == n;
    }
};
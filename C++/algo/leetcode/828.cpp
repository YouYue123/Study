// 828. Count Unique Characters of All Substrings of a Given String [H]
// LeetCode count-unique-characters-of-all-substrings-of-a-given-string

class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int ans = 0;
        int sum = 0;
        vector last(2, vector(26, -1));
        for(int i = 0; i < n; i ++) {
            int c = s[i] - 'A';
            sum += i - last[0][c];
            sum -= last[0][c] - last[1][c];
            last[1][c] = last[0][c];
            last[0][c] = i;
            ans += sum;
        }
        return ans;
    }
};
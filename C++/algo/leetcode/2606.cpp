// 2606. Find the Substring With Maximum Cost [M]
// LeetCode find-the-substring-with-maximum-cost

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> dict;
        for(int i = 0 ;i < chars.size(); i ++) {
            char c = chars[i];
            int v = vals[i];
            dict[c] = v;
        }
        int ans = 0;
        int curSum = 0;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            int score = int(c - 'a') + 1;
            if(dict.contains(c)) score = dict[c];
            curSum = max(score, curSum + score);
            ans = max(ans, curSum);
        }
        return ans;
    }
};
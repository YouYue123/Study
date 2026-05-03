// 2381. Shifting Letters II [M]
// LeetCode shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.size() + 1, 0);
        for(auto& s : shifts) {
            int delta = s[2] == 1 ? 1 : -1;
            diff[s[0]] += delta;
            diff[s[1] + 1] -= delta;
        }
        int cur = 0;
        string ans = "";
        for(int i = 0; i < s.size(); i ++) {
            cur += diff[i];
            char c = s[i];
            int pos = (((c - 'a') + cur) % 26 + 26) % 26;
            ans += (pos + 'a');
        }
        return ans;
    }
};
// 76. Minimum Window Substring [H]
// LeetCode minimum-window-substring

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> t_dict;
        for(char c : t) t_dict[c] += 1;
        int t_dict_size = t_dict.size();
        // cout << "t_dict " << t_dict.size() << endl;
        int left = 0, right = 0;
        unordered_map<char, int> s_dict;
        int match_cnt = 0;
        int ans_len = INF;
        int ans_left = -1;
        while(right < n) {
            s_dict[s[right]] += 1;
            if(s_dict[s[right]] == t_dict[s[right]]) {
                match_cnt += 1;
            }
            while(match_cnt == t_dict_size) {
                if(right - left + 1 < ans_len) {
                    ans_len = right - left + 1;
                    ans_left = left;
                }
                if(s_dict[s[left]] == t_dict[s[left]]) {
                    match_cnt -= 1;
                }
                s_dict[s[left]] -= 1;
                left += 1;
            }
            right += 1;
        }
        if(ans_len == INF) return "";
        return s.substr(ans_left, ans_len);
    }
};
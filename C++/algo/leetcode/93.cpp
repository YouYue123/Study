// 93. Restore IP Addresses [M]
// LeetCode restore-ip-addresses

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> ans;
        auto dfs = [&] (this auto&& dfs, int i, int cur, int cnt, string& tmp) {
            if(cur > 255) return;
            if(i == n && cnt == 3) {
                if(tmp.back() != '.') ans.push_back(tmp);
                return;
            }
            if(i == n || cnt > 3) return;
            if(!tmp.empty() && tmp.back() != '.') {
                tmp.push_back('.');
                dfs(i, 0, cnt + 1, tmp);
                tmp.pop_back();
            }
            if(tmp.empty() || (tmp.back() != '0' || cur != 0)) {
                cur = cur * 10 + (s[i] - '0');
                tmp.push_back(s[i]);
                dfs(i + 1, cur, cnt, tmp);
                tmp.pop_back();
            }
        };
        string tmp = "";
        dfs(0, 0, 0, tmp);
        return ans;
    }
};
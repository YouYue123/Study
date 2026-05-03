// 3900. Longest Balanced Substring After One Swap [M]
// LeetCode longest-balanced-substring-after-one-swap

class Solution {
public:
    int longestBalanced(string s) {
        int total0 = ranges::count(s, '0');
        int total1 = s.size() - total0;

        unordered_map<int, vector<int>> pos = {{0, {-1}}}; // 见 525 题
        int ans = 0;
        int sum = 0; // 前缀和

        for (int i = 0; i < s.size(); i++) {
            sum += (s[i] - '0') * 2 - 1;

            if (pos[sum].size() < 2) {
                pos[sum].push_back(i);
            }

            // 不交换
            ans = max(ans, i - pos[sum][0]);

            // 交换子串内的一个 1 和子串外的一个 0
            auto it = pos.find(sum - 2);
            if (it != pos.end()) {
                auto& p = it->second;
                if ((i - p[0] - 2) / 2 < total0) {
                    ans = max(ans, i - p[0]);
                } else if (p.size() > 1) {
                    ans = max(ans, i - p[1]);
                }
            }

            // 交换子串内的一个 0 和子串外的一个 1
            it = pos.find(sum + 2);
            if (it != pos.end()) {
                auto& p = it->second;
                if ((i - p[0] - 2) / 2 < total1) {
                    ans = max(ans, i - p[0]);
                } else if (p.size() > 1) {
                    ans = max(ans, i - p[1]);
                }
            }
        }

        return ans;
    }
};
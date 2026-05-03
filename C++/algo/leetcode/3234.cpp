// 3234. Count the Number of Substrings With Dominant Ones [M]
// LeetCode count-the-number-of-substrings-with-dominant-ones

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int oneCnt = 0;
        vector<int> pos0 = {-1};
        for(int r = 0; r < s.size(); r ++) {
            if(s[r] == '1') {
                oneCnt += 1;
                ans += r - pos0.back();
            } else {
                pos0.push_back(r);
            }
            for(int i = pos0.size() - 1; i > 0 && (pos0.size() - i) * (pos0.size() - i) <= oneCnt; i --) {
                int p = pos0[i - 1], q = pos0[i];
                int cnt0 = pos0.size() - i;
                int cnt1 = r - q + 1 - cnt0;
                ans += max(q - max(cnt0 * cnt0 - cnt1, 0) - p, 0);
            }
        }
        return ans;
    }
};
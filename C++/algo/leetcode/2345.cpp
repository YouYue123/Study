// 2345. Finding the Number of Visible Mountains [M]
// LeetCode finding-the-number-of-visible-mountains

using pii = pair<int, int>;
int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        int n = peaks.size();        
        map<pii, int> cnts;
        for (auto& p : peaks) {
            cnts[{p[0], p[1]}]++;
        }
        sort(peaks.begin(), peaks.end(), [](const vector<int>& a, const vector<int>& b) {
            int l1 = a[0] - a[1], r1 = a[0] + a[1];
            int l2 = b[0] - b[1], r2 = b[0] + b[1];
            if (l1 != l2) return l1 < l2;
            return r1 > r2;
        });

        int ans = 0;
        int maxR = -INF;

        for (int i = 0; i < n; i++) {
            int curL = peaks[i][0] - peaks[i][1];
            int curR = peaks[i][0] + peaks[i][1];
            if (curR > maxR) {
                maxR = curR;
                if (cnts[{peaks[i][0], peaks[i][1]}] == 1) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
// 2555. Maximize Win From Two Segments [M]
// LeetCode maximize-win-from-two-segments

class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int ans = 0, n = prizePositions.size();
        int left = 0, right = 0;
        vector<int> dp(n + 1, 0);
        while(right < n) {
            while(prizePositions[right] - prizePositions[left] > k) {
                left += 1;
            }
            dp[right + 1] = max(dp[right], right - left + 1);
            ans = max(ans, right - left + 1 + dp[left]);
            right += 1;
        }
        return ans;
    }
};
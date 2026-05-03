// 3208. Alternating Groups II [M]
// LeetCode alternating-groups-ii

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int count = 0;
        int lastColor = INT_MAX;
        for(int i = 0; i < n + k - 1; i ++) {
            int index = i % n;
            if (colors[index] == lastColor) {
                lastColor = colors[index];
                count = 1;
                continue;
            }
            count += 1;
            if (count >= k) ans += 1;
            lastColor = colors[index];
        }
        return ans;
    }
};
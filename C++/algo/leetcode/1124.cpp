// 1124. Longest Well-Performing Interval [M]
// LeetCode longest-well-performing-interval

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        for (int i = 0; i < hours.size(); ++i) {
            sum += (hours[i] > 8 ? 1 : -1);
            if (sum > 0) ans = max(ans, i + 1);
            else if (dict.contains(sum - 1)) ans = max(ans, i - dict[sum - 1]);
            if (!dict.contains(sum)) dict[sum] = i;
        }
        return ans;
    }
};

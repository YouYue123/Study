// 370. Range Addition [M]
// LeetCode range-addition

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length + 1, 0);
        for(auto& update : updates) {
            int start = update[0], end = update[1], inc = update[2];
            diff[start] += inc;
            diff[end + 1] -= inc;
        }
        vector<int> ans(length);
        int curSum = 0;
        for(int i = 0; i < length; i ++) {
            curSum += diff[i];
            ans[i] = curSum;
        }
        return ans;
    }
};
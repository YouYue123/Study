// 1854. Maximum Population Year [E]
// LeetCode maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(2052, 0);
        for(vector<int>& log : logs) {
            diff[log[0]] += 1;
            diff[log[1]] -= 1;
        }
        int cur = 0;
        int ans = 1949;
        int curMax = INT_MIN;
        for(int i = 1950; i <= 2050; i ++) {
            cur += diff[i];
            if(cur > curMax) {
                curMax = cur;
                ans = i;
            }
        }
        return ans;
    }
};
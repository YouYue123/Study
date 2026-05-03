// 2848. Points That Intersect With Cars [E]
// LeetCode points-that-intersect-with-cars

class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int> diff(102, 0);
        for(vector<int>& p : nums) {
            diff[p[0]] += 1;
            diff[p[1] + 1] -= 1;
        }
        int cur = 0;
        int ans = 0;
        for(int i = 0; i <= 100; i ++) {
            cur += diff[i];
            if(cur != 0) ans += 1;
        }
        return ans;
    }
};
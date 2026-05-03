// 1716. Calculate Money in Leetcode Bank [E]
// LeetCode calculate-money-in-leetcode-bank


class Solution {
public:
    int totalMoney(int n) {
        int day = 0;
        int ans = 0;
        vector<int> weekMap = {
            1,2,3,4,5,6,7
        };
        while(day < n) {
            ans += weekMap[day % 7];
            // cout << day << " " << ans << endl;
            weekMap[day % 7] += 1;
            day += 1;
        }
        return ans;
    }
};
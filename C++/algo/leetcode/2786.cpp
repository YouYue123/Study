// 2786. Visit Array Positions to Maximize Score [M]
// LeetCode visit-array-positions-to-maximize-score

class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        long long ans = nums[0];
        long long curOddMax = ans % 2 != 0 ? ans : -x;
        long long curEvenMax = ans % 2 == 0 ? ans : -x;
        for(int i = 1; i < n; i ++) {
            int num = nums[i];
            if(num % 2 != 0) {
                curOddMax = max(
                    curOddMax + num,
                    curEvenMax + num - x
                );
                ans = max(ans, curOddMax);
            } else {
                curEvenMax = max(
                    curEvenMax + num,
                    curOddMax + num - x
                );
                ans = max(ans, curEvenMax);
            }
            // cout << curOddMax << " " << curEvenMax << endl;
        };
        return ans;
    }
};
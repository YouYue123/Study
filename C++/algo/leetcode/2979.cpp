// 2979. Most Expensive Item That Can Not Be Bought [M]
// LeetCode most-expensive-item-that-can-not-be-bought

class Solution {
public:
    int mostExpensiveItem(int primeOne, int primeTwo) {
        int ans = 0;
        vector<bool> dp;
        dp.push_back(true);
        for(int i = 1; i < primeOne * primeTwo; i ++) {
            // cout << i;
            dp.push_back(false);
            if (i - primeOne >= 0 && dp[i - primeOne]) {
                dp[i] = true;
            } 
            if (i - primeTwo >= 0 && dp[i - primeTwo]) {
                dp[i] = true;
            }
            if(dp[i] == false) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};
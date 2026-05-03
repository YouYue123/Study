// 3366. Minimum Array Sum [M]
// LeetCode minimum-array-sum

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        auto applyOp1 = [&] (int num) {
            return (num + 1) / 2;
        };
        auto applyOp2 = [&] (int num) {
            return num - k;
        };
        vector memo(n, vector(op1 + 1, vector(op2 + 1, -1)));
        // for(int i = 0; i < n; i ++) memo[i][0][0] = 
        auto dfs = [&] (this auto&& dfs, int i, int op1Cnt, int op2Cnt) {
            if(op1Cnt > op1 || op2Cnt > op2) return INF;
            if(i == n) return 0;
            if(memo[i][op1Cnt][op2Cnt] != -1) return memo[i][op1Cnt][op2Cnt];
            int num = nums[i];
            int ans = dfs(i + 1, op1Cnt, op2Cnt) + num;
            // op1
            ans = min(
                ans, 
                dfs(i + 1, op1Cnt + 1, op2Cnt) + applyOp1(num)
            );        
            if(num >= k) {
                // op2
                ans = min(
                    ans, 
                    dfs(i + 1, op1Cnt, op2Cnt + 1) + applyOp2(num)
                );
                // op2 first, op1 second
                ans = min(
                    ans, 
                    dfs(i + 1, op1Cnt + 1, op2Cnt + 1) + applyOp1(applyOp2(num))
                );
            }
            // op1 first, op2 second
            if(applyOp1(num) >= k) {
                ans = min(
                    ans, 
                    dfs(i + 1, op1Cnt + 1, op2Cnt + 1) + applyOp2(applyOp1(num))
                );
            }
            return memo[i][op1Cnt][op2Cnt] = ans;
        };
        return dfs(0, 0, 0);
    }
};
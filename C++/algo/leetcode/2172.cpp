// 2172. Maximum AND Sum of Array [H]
// LeetCode maximum-and-sum-of-array

int constexpr INF = 0x3f3f3f3f;
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size();
        vector<int> memo(1 << (2 * numSlots), -1);        
        auto dfs = [&] (this auto&& dfs, int i, int mask) {
            if(i == n) return 0;
            if(memo[mask] != -1) return memo[mask];
            int ans = 0;
            for(int j = 0; j < numSlots; j ++) {
                int shift = j * 2;
                int cnt = (mask >> shift) & 3;
                if(cnt < 2) {
                    ans = max(
                        ans,
                        dfs(i + 1, mask + (1 << shift)) + (nums[i] & (j + 1))
                    );
                }
            }
            return memo[mask] = ans;
        };
        return dfs(0, 0);
    }
};
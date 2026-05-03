// 3599. Partition Array to Minimize XOR [M]
// LeetCode partition-array-to-minimize-xor

class Solution {
public:
    int minXor(vector<int>& nums, int k) {
        int n = nums.size();
        vector memo(n, vector(k + 1, -1));
        auto dfs = [&] (this auto&& dfs, int i, int cnt) {
            if(cnt > k) return INT_MAX;
            if(i == n) return cnt == k ? 0 : INT_MAX;
            if(memo[i][cnt] != -1) return memo[i][cnt];
            int xorPreSum = 0;
            int ans = INT_MAX;
            for(int j = i; j < n; j ++) {
                xorPreSum ^= nums[j];
                int remain = dfs(j + 1, cnt + 1);
                if(remain != INT_MAX) ans = min(ans, max(xorPreSum, remain));
            }
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0);
    }
};
// 2552. Count Increasing Quadruplets [H]
// LeetCode count-increasing-quadruplets

class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        // Get the size of the input array.
        int n = nums.size();
        
        // `great[k][x]` stores the count of numbers greater than `x` to the right of index `k`.
        // The size is `n x (n + 1)` because numbers can range from 1 to `n`.
        vector<vector<int>> great(n, vector<int>(n + 1));
        
        // Iterate from `n - 2` down to `2` to precompute `great` array.
        // `k` represents the third element's index in a quadruplet (nums[i] < nums[k] > nums[j] < nums[l]).
        for(int k = n - 2; k >= 2; k --) {
            // Initialize `great[k]` with `great[k + 1]`. This carries over counts from the right.
            great[k] = great[k + 1];
            
            // For each number `x` less than `nums[k + 1]`, increment its count in `great[k]`.
            // This means `nums[k + 1]` is greater than `x`.
            for(int x = 1; x < nums[k + 1]; x ++) {
                great[k][x] += 1;
            }
        }
        
        // Initialize the answer to 0. This will store the total count of valid quadruplets.
        long long ans = 0;
        
        // `less[x]` stores the count of numbers less than `x` to the left of the current index `j`.
        // The size is `n + 1` because numbers can range from 1 to `n`.
        vector<int> less(n + 1);
        
        // Iterate from `j = 1` to `n - 3`. `j` represents the second element's index.
        for(int j = 1; j < n - 2; j ++) {
            // For each number `x` greater than `nums[j - 1]`, increment its count in `less`.
            // This means `nums[j - 1]` is less than `x`.
            for(int x = nums[j - 1] + 1; x <= n; x ++) less[x] += 1;
            
            // Iterate from `k = j + 1` to `n - 2`. `k` represents the third element's index.
            for(int k = j + 1; k < n - 1; k ++) {
                // Check the condition `nums[j] > nums[k]`.
                // This corresponds to `a < c` and `b > d` in the problem statement
                // (where `a = nums[i]`, `b = nums[j]`, `c = nums[k]`, `d = nums[l]`).
                if(nums[j] > nums[k]) {
                    // If the condition holds, we need to find `i` such that `nums[i] < nums[k]`
                    // and `l` such that `nums[l] < nums[j]`.
                    // `less[nums[k]]` gives the count of `nums[i]` (left of `j`) such that `nums[i] < nums[k]`.
                    // `great[k][nums[j]]` gives the count of `nums[l]` (right of `k`) such that `nums[l] < nums[j]`.
                    ans += (long long)less[nums[k]] * great[k][nums[j]];
                }
            }
        }
        
        // Return the total count of valid quadruplets.
        return ans;
    }
};
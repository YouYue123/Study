// 3909. Compare Sums of Bitonic Parts [M]
// LeetCode compare-sums-of-bitonic-parts

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long pre_sum = 0;
        long long total_sum = accumulate(nums.begin(), nums.end(), 0LL);
        for(int i = 0; i < n - 1; i ++) {
            if(nums[i] > nums[i + 1]) {
                long long suf_sum = total_sum - pre_sum - nums[i];
                // cout << pre_sum << " " << suf_sum << endl;
                if(pre_sum == suf_sum) return -1;
                else if(pre_sum > suf_sum) return 0;
                else return 1;
            }
            pre_sum += nums[i];
        }
        return 0;
    }
};
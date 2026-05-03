// 3566. Partition Array into Two Equal Product Subsets [M]
// LeetCode partition-array-into-two-equal-product-subsets

class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 prod = 1;
        for (int v : nums) prod *= v;
        __int128 tgt = (__int128)target * target;
        return prod == tgt;
    }
};
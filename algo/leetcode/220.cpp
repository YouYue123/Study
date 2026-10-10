#include <bits/stdc++.h>
using namespace std;

// 220. Contains Duplicate III [H]
// LeetCode contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if (nums.empty() || indexDiff <= 0 || valueDiff < 0) {
            return false;
        }
        
        unordered_map<long, long> buckets;
        long bucket_size = (long)valueDiff + 1;
        
        for (int i = 0; i < nums.size(); ++i) {
            long num = (long)nums[i] - INT_MIN; // 处理负数情况
            long bucket = num / bucket_size;
            
            // 检查当前桶是否已有元素
            if (buckets.contains(bucket)) {
                return true;
            }
            // 检查相邻桶
            if (buckets.contains(bucket - 1) && num - buckets[bucket - 1] <= valueDiff) {
                return true;
            }
            if (buckets.contains(bucket + 1) && buckets[bucket + 1] - num <= valueDiff) {
                return true;
            }
            
            // 放入当前元素
            buckets[bucket] = num;
            
            // 维护窗口大小不超过indexDiff
            if (i >= indexDiff) {
                long old_num = (long)nums[i - indexDiff] - INT_MIN;
                long old_bucket = old_num / bucket_size;
                buckets.erase(old_bucket);
            }
        }
        
        return false;
    }
};
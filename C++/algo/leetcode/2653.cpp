// 2653. Sliding Subarray Beauty [M]
// LeetCode sliding-subarray-beauty

class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        unordered_map<int, int> dict;
        vector<int> ans;
        int left = 0, right = 0;
        while(right < nums.size()) {
            dict[nums[right]] += 1;
            if(right - left + 1 > k) {
                dict[nums[left]] -= 1;
                left += 1;
            }
            if(right - left + 1 == k) {
                int count = x;
                for(int val = -50; val <= -1; val ++) {
                    count -= dict[val];
                    if(count <= 0) {
                        ans.push_back(val);
                        break;
                    }
                }
                if(count > 0) ans.push_back(0);
             }
             right += 1;
        }
        return ans;
    }
};
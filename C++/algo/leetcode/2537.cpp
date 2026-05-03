// 2537. Count the Number of Good Subarrays [M]
// LeetCode count-the-number-of-good-subarrays

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> dict;
        int left = 0, right = 0;
        long long ans = 0;
        while(right < nums.size()) {
            count += dict[nums[right]];
            dict[nums[right]] += 1; 
            while(count >= k) {
                dict[nums[left]] -= 1;
                count -= dict[nums[left]];
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
};
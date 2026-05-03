// 3134. Find the Median of the Uniqueness Array [H]
// LeetCode find-the-median-of-the-uniqueness-array

class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = (long long) n * (n + 1) / 2;
        auto isValid = [&](int k){
            long long ans = 0;
            int left = 0, right = 0;
            unordered_map<int, int> dict;
            while(right < n) {
                dict[nums[right]] += 1;
                while(dict.size() > k) {
                    dict[nums[left]] -= 1;
                    if(dict[nums[left]] == 0) dict.erase(nums[left]);
                    left += 1;
                }
                ans += right - left + 1;
                right += 1;
            }
            return ans * 2 >= total;
        };
        int left = 1, right = unordered_set<int>(nums.begin(), nums.end()).size();
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
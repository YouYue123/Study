// 3041. Maximize Consecutive Elements in an Array After Modification [H]
// LeetCode maximize-consecutive-elements-in-an-array-after-modification

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dict;
        int ans = 0;
        for(int num : nums) {
            dict[num + 1] = dict[num] + 1;
            dict[num] = dict[num - 1] + 1;
            ans = max({ans, dict[num + 1], dict[num]});
        }
        return ans;
    }
};
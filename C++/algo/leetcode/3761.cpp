// 3761. Minimum Absolute Distance Between Mirror Pairs [M]
// LeetCode minimum-absolute-distance-between-mirror-pairs

class Solution {
public:
    int reverse(int num) {
        int ans = 0;
        while(num) {
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        return ans;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> dict;
        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i ++) {
            int target = reverse(nums[i]);
            // cout << nums[i] << " " << target << endl;
            if(dict.contains(nums[i])) ans = min(ans, i - dict[nums[i]]);
            dict[target] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
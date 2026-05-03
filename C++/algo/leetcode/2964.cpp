// 2964. Number of Divisible Triplet Sums [M]
// LeetCode number-of-divisible-triplet-sums

class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        int ans = 0;
        for(int j = 1; j < nums.size() - 1; j ++) {
            unordered_map<int, int> dict;
            for(int i = 0; i < j; i ++) {
                dict[(nums[i] + nums[j]) % d] += 1;
            }
            for(int k = j + 1; k < nums.size(); k ++) {
                int comple = (d - (nums[k] % d)) % d;
                // cout << nums[k] << " " << comple << endl;
                ans += dict[comple];
            }
            // cout << ans << endl;
        }
        return ans;
    }
};
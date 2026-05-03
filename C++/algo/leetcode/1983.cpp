// 1983. Widest Pair of Indices With Equal Range Sum [M]
// LeetCode widest-pair-of-indices-with-equal-range-sum

class Solution {
public:
    int widestPairOfIndices(vector<int>& nums1, vector<int>& nums2) {
        int sum = 0;
        unordered_map<int, int> dict;
        dict[0] = -1;
        int ans = INT_MIN;
        for(int i = 0; i < nums1.size(); i ++) {
            int diff = nums1[i] - nums2[i];
            // cout << diff << " " << endl;
            sum += diff;
            if(dict.contains(sum)) {
                ans = max(ans, i - dict[sum]);
            } else {
                dict[sum] = i;
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};
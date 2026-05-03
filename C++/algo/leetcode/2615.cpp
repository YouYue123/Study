// 2615. Sum of Distances [M]
// LeetCode sum-of-distances

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int, vector<long long>> dict;
        vector<long long> ans (nums.size(), -1);
        for(int i = 0; i < nums.size(); i ++) {
            dict[nums[i]].push_back(i);
        }
        for(auto& [_, idxes]: dict) {
            int m = idxes.size();
            vector<long long> presum(m + 1, 0);
            for(int i = 1; i <= m; i ++) {
                presum[i] = presum[i - 1] + idxes[i - 1];
            }
            for(long long j = 0; j < m; j ++) {
                int target = idxes[j];
                long long pre = j * target - presum[j];
                long long post = (presum[m] - presum[j]) - target * (m - j);
                ans[idxes[j]] = pre + post;
            }
        }
        return ans;
    }
};
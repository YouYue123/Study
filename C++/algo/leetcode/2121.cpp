// 2121. Intervals Between Identical Elements [M]
// LeetCode intervals-between-identical-elements

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        unordered_map<int, vector<int>> dict;
        for(int i = 0; i < arr.size(); i ++) {
            dict[arr[i]].push_back(i);
        }
        vector<long long> ans(arr.size(), 0);
        for(auto& [_, idxes] : dict) {
            int m = idxes.size();
            vector<long long> presum(m + 1, 0);
            for(int i = 1; i <= m; i ++) {
                presum[i] = presum[i - 1] + (long long)idxes[i - 1];
            }
            for(int i = 0; i < m; i ++) {
                long long target = idxes[i];
                long long pre = i * target - presum[i];
                long long post = (presum[m] - presum[i]) - (m - i) * target;
                ans[target] = pre + post;
            }
        }
        return ans;
    }
};
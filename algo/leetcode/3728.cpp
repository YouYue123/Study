#include <bits/stdc++.h>
using namespace std;

// 3728. Stable Subarrays With Equal Boundary and Interior Sum [M]
// LeetCode stable-subarrays-with-equal-boundary-and-interior-sum

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        // cap[l] = cap[r] = presum[r] - presum[l + 1]
        int n = capacity.size();
        vector<long long> presum(n + 1);
        for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + capacity[i];
        unordered_map<int, vector<int>> indices;
        for(int i = 0; i < n; i ++) {
            int cur = capacity[i];
            indices[cur].push_back(i);
        }
        long long ans = 0;
        for(auto& pair: indices) {
            int C = pair.first;
            vector<int>& indice_list = pair.second;
            unordered_map<long long, int> valid_cnts;
            
            int l_idx = 0;
            for(int r_idx = 0; r_idx < indice_list.size(); r_idx += 1) {
                int r = indice_list[r_idx];
                while(l_idx < r_idx && indice_list[l_idx] <= r - 2) {
                    int l = indice_list[l_idx];
                    valid_cnts[presum[l + 1]] += 1;
                    l_idx += 1;
                }
                long long target = presum[r] - C;
                 ans += valid_cnts[target];
            }
        }
        return ans;
    }
};
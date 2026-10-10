#include <bits/stdc++.h>
using namespace std;

// 1310. XOR Queries of a Subarray [M]
// LeetCode xor-queries-of-a-subarray

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> presum(arr.size() + 1, 0);
        for(int i = 1; i <= arr.size(); i ++) {
            presum[i] = presum[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for(auto& q : queries) {
            ans.push_back(
                presum[q[1] + 1] ^ presum[q[0]]
            );
        }
        return ans;
    }
};
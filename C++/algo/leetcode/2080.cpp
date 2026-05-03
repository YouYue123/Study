#include <bits/stdc++.h>
using namespace std;

// 2080. Range Frequency Queries [M]
// LeetCode range-frequency-queries

class RangeFreqQuery {
public:
    unordered_map<int, vector<int>> dict;
    RangeFreqQuery(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i ++) {
            dict[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int val) {
        auto it1 = lower_bound(dict[val].begin(), dict[val].end(), left);
        auto it2 = upper_bound(dict[val].begin(), dict[val].end(), right);
        return it2 - it1;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
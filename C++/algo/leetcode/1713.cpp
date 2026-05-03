// 1713. Minimum Operations to Make a Subsequence [H]
// LeetCode minimum-operations-to-make-a-subsequence

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> dict;
        for(int i = 0; i < target.size(); i ++) {
            dict[target[i]] = i;
        }
        vector<int> seq;
        for(int num : arr) {
            if(dict.contains(num)) seq.push_back(dict[num]);
        }
        vector<int> g;
        for(int x : seq) {
            int idx = lower_bound(g.begin(), g.end(), x) - g.begin();
            if(idx == g.size()) g.push_back(x);
            else g[idx] = x;
        }
        return target.size() - g.size();
    }
};
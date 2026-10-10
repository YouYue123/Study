#include <bits/stdc++.h>
using namespace std;

// 3480. Maximize Subarrays After Removing One Conflicting Pair [H]
// LeetCode maximize-subarrays-after-removing-one-conflicting-pair

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        vector<vector<int>> groups(n + 1);
        for(auto &p : conflictingPairs) {
            int a = p[0], b = p[1];
            if(a > b) swap(a, b);
            groups[a].push_back(b);
        }
        // for(auto& item : groups) {
        //     for(int t : item) {
        //         cout << t << " ";
        //     }
        //     cout << endl;
        // }
        long long ans = 0;
        vector<long long> extra(n + 2);
        vector<int> b = {n + 1, n + 1};
        for(int i = n; i > 0; i --) {
            b.insert(b.end(), groups[i].begin(), groups[i].end());
            ranges::sort(b);
            b.resize(2);
            ans += b[0] - i;
            extra[b[0]] += b[1] - b[0];
        }
        return ans + ranges::max(extra);
    }
};
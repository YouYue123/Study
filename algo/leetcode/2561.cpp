#include <bits/stdc++.h>
using namespace std;

// 2561. Rearranging Fruits [H]
// LeetCode rearranging-fruits

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt;
        for(int i = 0 ; i < basket1.size(); i ++) {
            cnt[basket1[i]] += 1;
            cnt[basket2[i]] -= 1;
        }
        vector<int> a, b;
        int curMin = INT_MAX;
        for(auto & p : cnt) {
            if(p.second % 2 != 0) return -1;
            curMin = min(curMin, p.first);
            if(p.second > 0) {
                for(int i = 0; i < p.second / 2; i ++) a.push_back(p.first);
            } else {
                for(int i = 0; i < -p.second / 2; i ++) b.push_back(p.first);
            }
        }
        long long ans = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());
        assert(a.size() == b.size());
        // cout << a.size() << " " << b.size() << endl;
        for(int i = 0; i < a.size(); i ++) {
            ans += min({a[i], b[i], 2 * curMin });
        }
        return ans;
    }
};
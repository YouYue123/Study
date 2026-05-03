#include <bits/stdc++.h>
using namespace std;

// 2589. Minimum Time to Complete All Tasks [H]
// LeetCode minimum-time-to-complete-all-tasks

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [&](auto& a, auto& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<array<int,3>> st = {{-2, -2, 0}};
        for(auto& t : tasks) {
            int s = t[0], e = t[1], d = t[2];
            auto [_, r1, d1] = *--lower_bound(
                st.begin(), st.end(), t,
                [&](auto& a, auto& b) {
                    return a[0] < b[0];
                }
            );
            d -= st.back()[2] - d1;
            if(s <= r1) d -= r1 - s + 1;
            if(d <= 0) continue;
            // If can merge
            while(e - d + 1 <= st.back()[1]) {
                auto [l2, r2, _] = st.back();
                st.pop_back();
                d += r2 - l2 + 1;
            }
            st.push_back({
                e - d + 1,
                e,
                st.back()[2] + d,
            });
        }
        return st.back()[2];
    }
};
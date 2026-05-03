#include <bits/stdc++.h>
using namespace std;

// 757. Set Intersection Size At Least Two [H]
// LeetCode set-intersection-size-at-least-two

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b) {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });
        vector<array<int, 3>> st = {{-2, -2, 0}};
        for(auto& interval : intervals) {
            int s = interval[0], e = interval[1], d = 2;
            auto [_, r1, d1] = *--lower_bound(
                st.begin(), st.end(), interval,
                [&] (auto& a, auto& b) {
                    return a[0] < b[0];
                }
            ); 
            d -= st.back()[2] - d1;
            if(s <= r1) d -= r1 - s + 1;
            if(d <= 0) continue;
            while(e - d + 1 <= st.back()[1]) {
                auto [l2, r2, _] = st.back();
                st.pop_back();
                d += r2 - l2 + 1;
            } 
            st.push_back({
                e - d + 1,
                e,
                st.back()[2] + d
            });
        }
        return st.back()[2];
    }
};
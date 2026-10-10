#include <bits/stdc++.h>
using namespace std;

// 3414. Maximum Score of Non-overlapping Intervals [H]
// LeetCode maximum-score-of-non-overlapping-intervals

struct Ans {
    long long weight = -1;
    vector<int> idxes;
    bool operator>(const Ans& other) const {
        if(weight == other.weight) return idxes < other.idxes;
        return weight > other.weight;
    }
};
struct Item {
    int l;
    int r;
    int w;
    int idx;
};
class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Item> items;
        for(int i = 0; i < n; i ++) {
            auto& interval = intervals[i];
            items.emplace_back(interval[0], interval[1], interval[2], i);
        }
        sort(items.begin(), items.end(), [&](auto& a, auto& b) {
            return a.l < b.l;
        });
        vector memo(n, vector(4, Ans(-1, {})));
        auto dfs = [&](this auto&& dfs, int i, int cnt) -> Ans {
            if(i == n || cnt == 4) return { 0, {} };
            if(memo[i][cnt].weight != -1) return memo[i][cnt];
            auto ans = dfs(i + 1, cnt);
            int left = i + 1, right = n - 1, idx = -1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(items[mid].l > items[i].r) {
                    right = mid - 1;
                    idx = mid;
                } else {
                    left = mid + 1;
                }
            }
            Ans choose = { 0, {} };
            if(idx != -1) choose = dfs(idx, cnt + 1);
            choose.weight += items[i].w;
            choose.idxes.push_back(items[i].idx);
            sort(choose.idxes.begin(), choose.idxes.end());
            if(choose > ans) ans = choose;
            return memo[i][cnt] = ans;
        };
        return dfs(0, 0).idxes;
    }
};
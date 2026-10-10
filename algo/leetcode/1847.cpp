#include <bits/stdc++.h>
using namespace std;

int constexpr INF = 0x3f3f3f3f;
struct Query {
    int idx;
    int prefered;
    int min_size;
};
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), m = queries.size();
        vector<int> ans(m);
        sort(rooms.begin(), rooms.end(), [&] (auto& a, auto& b) {
            return a[1] > b[1];
        });
        vector<Query> qs;
        for(int i = 0; i < m; i ++) {
            qs.emplace_back(i, queries[i][0], queries[i][1]);
        }
        sort(qs.begin(), qs.end(), [&] (auto& a, auto& b) {
            return a.min_size > b.min_size;
        });
        int p = 0;
        set<int> valid_room_ids;
        for(auto& q : qs) {
            while(p < n && rooms[p][1] >= q.min_size) {
                valid_room_ids.insert(rooms[p][0]);
                p += 1;
            }
            auto it = valid_room_ids.lower_bound(q.prefered);
            int cur_id = it != valid_room_ids.end() ? *it : INF;
            int prev_id = it != valid_room_ids.begin() ? *(prev(it)) : INF;
            if(cur_id == INF && prev_id == INF) {
                ans[q.idx] = -1;
                continue;
            }
            if(abs(q.prefered - prev_id) <= abs(q.prefered - cur_id)) {
                ans[q.idx] = prev_id;
            } else {
                ans[q.idx] = cur_id;
            }
        }
        return ans;
    }
};
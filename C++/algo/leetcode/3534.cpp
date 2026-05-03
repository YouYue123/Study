// 3534. Path Existence Queries in a Graph II [H]
// LeetCode path-existence-queries-in-a-graph-ii

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> A(n);
        for(int i = 0; i < n; i ++) A[i] = { nums[i], i };
        sort(A.begin(), A.end());
        vector<int> sorted(n), pos(n);
        for(int i = 0; i < n; ++i) {
            sorted[i] = A[i].first;
            pos[A[i].second] = i;
        }
        vector<int> R(n);
        for(int i = 0; i < n; ++i) {
            int h = upper_bound(sorted.begin(), sorted.end(), sorted[i] + maxDiff) - sorted.begin() - 1;
            R[i] = h;
        }
        int LOG = 1;
        while(1 << LOG <= n) ++LOG;
        vector<vector<int>> jump(LOG, vector<int>(n));
        jump[0] = R;
        for(int k = 1; k < LOG; ++k) {
            for(int i = 0; i < n; ++i) {
              jump[k][i] = jump[k-1][ jump[k-1][i] ];
            }
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for(auto &q : queries) {
            int u = pos[q[0]], v = pos[q[1]];
            if(u > v) swap(u, v);
            if(u == v) {
                ans.push_back(0);
                continue;
            }
            if(R[u] <= u) {
                ans.push_back(-1);
                continue;
            }
            int hops = 0, cur = u;
            for(int k = LOG - 1; k >=0; --k) {
                int next = jump[k][cur];
                if(next < v) {
                    hops += 1 << k;
                    cur = next;
                }
            }
            if(R[cur] < v) ans.push_back(-1);
            else ans.push_back(hops + 1);
        }
        return ans;
    }
};
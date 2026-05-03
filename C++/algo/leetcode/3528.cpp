// 3528. Unit Conversion I [M]
// LeetCode unit-conversion-i

int MOD = 1e9 + 7;
struct Edge {
    int to;
    long long val;
};
class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        unordered_map<int, vector<Edge>> g;
        for(auto& c : conversions) {
            int source = c[0], target = c[1], val = c[2];
            g[source].emplace_back(target, val);
        }
        vector<int> ans(n + 1, 0);
        queue<Edge> q;
        q.emplace(0, 1);
        vector visit(n + 1, false);
        visit[0] = true;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            ans[cur.to] = cur.val;
            for(auto& nxt : g[cur.to]) {
                int nTo = nxt.to;
                if(visit[nTo]) continue;
                visit[nTo] = true;
                int nVal = (cur.val * nxt.val) % MOD;
                q.emplace(nTo, nVal);
            }
        }
        return ans;
     }
};
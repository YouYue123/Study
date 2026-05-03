// 399. Evaluate Division [M]
// LeetCode evaluate-division

struct Edge {
    string key;
    double val;
};
struct Node {
    string key;
    double val;
    int cnt;
    bool operator > (const Node& other) {
        return cnt > other.cnt;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // graph(a -> b with val)
        // query (x -> y)
        int n = equations.size();
        assert(equations.size() == values.size());
        unordered_map<string, vector<Edge>> g;
        for(int i = 0; i < n; i ++) {
            const string& from = equations[i][0], to = equations[i][1];
            const double val = values[i];
            g[from].emplace_back(to, val);
            g[to].emplace_back(from, 1.0 / val);
        }
        auto find = [&] (const string& from, const string& to) -> double {
            // queue<Edge> q;
            // q.emplace(from, 1.0);
            // unordered_map<string, bool> visited;
            // while(!q.empty()) {
            //     auto cur = q.front();
            //     q.pop();
            //     if(cur.key == to) return cur.val;
            //     for(auto& nxt : g[cur.key]) {
            //         string& nKey = nxt.key;
            //         if(visited[nKey]) continue;
            //         visited[nKey] = true;
            //         double nVal = cur.val * nxt.val;
            //         q.emplace(nKey, nVal);
            //     }
            // }
            // return -1.0;
            priority_queue<Node, vector<Node>, greater<>> pq;
            pq.emplace(from, 1.0, 0);
            unordered_map<string, int> dist;
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                if(cur.key == to) return cur.val;
                for(auto& nxt : g[cur.key]) {
                    string& nKey = nxt.key;
                    int nCnt = cur.cnt + 1;
                    if(dist.contains(nKey) && nCnt >= dist[nKey]) continue;
                    dist[nKey] = nCnt;
                    double nVal = cur.val * nxt.val;
                    pq.emplace(nKey, nVal, nCnt);
                }
            }
            return -1.0;
        };
        vector<double> ans;
        for(auto& q : queries) {
            const string& from = q[0], to = q[1];
            if(!g.contains(from) || !g.contains(to)) {
                ans.push_back(-1);
            } else {
                ans.push_back(
                    find(from, to)
                );
            }
        }
        return ans;
    }
};
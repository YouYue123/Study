// 2976. Minimum Cost to Convert String I [M]
// LeetCode minimum-cost-to-convert-string-i

long long constexpr INF = 0x3f3f3f3f3f3f3f3f; 
using pii = pair<int, int>;
struct Node {
    long long dist;
    int character;
    bool operator > (const Node& other) const {
        return dist > other.dist;
    }
};
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size(), m = source.size();
        unordered_map<int, vector<pii>> g;
        for(int i = 0 ; i < n; i ++) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            int c = cost[i];
            g[from].emplace_back(to, c);
        }
        priority_queue<Node, vector<Node>, greater<>> pq;
        vector dist(26, vector(26, INF));
        for(int start = 0; start < 26; start ++) {
            priority_queue<Node, vector<Node>, greater<>> pq;
            dist[start][start] = 0;
            pq.emplace(0, start);
            while(!pq.empty()) {
                auto cur = pq.top();
                pq.pop();
                int curC = cur.character;
                int curD = cur.dist;
                for(auto& nxt : g[curC]) {
                    int nxtC = nxt.first;
                    int nxtD = curD + nxt.second;
                    if(nxtD >= dist[start][nxtC]) continue;
                    dist[start][nxtC] = nxtD;
                    pq.emplace(nxtD, nxtC);
                }
            }
        }
       
        long long ans = 0;
        for(int i = 0; i < m; i ++) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if(dist[from][to] == INF) return -1;
            ans += dist[from][to];
        }
        return ans;
    }
};
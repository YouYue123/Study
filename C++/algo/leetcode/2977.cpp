// 2977. Minimum Cost to Convert String II [H]
// LeetCode minimum-cost-to-convert-string-ii


long long constexpr INF = 0x3f3f3f3f3f3fLL;


class Trie {
    struct Node {
        int child[26] = {0};
        int id = -1;
    };
    vector<Node> nodes;
    int id_ptr = 0;

public:
    Trie() { nodes.emplace_back(); } // 根节点

    // 插入并返回 ID。如果 create 为 false 且不存在，则返回 -1
    int get_id(const string& s, bool create) {
        int u = 0;
        for (char c : s) {
            int v = c - 'a';
            if (!nodes[u].child[v]) {
                if (!create) return -1;
                nodes[u].child[v] = nodes.size();
                nodes.emplace_back();
            }
            u = nodes[u].child[v];
        }
        if (create && nodes[u].id == -1) nodes[u].id = id_ptr++;
        return nodes[u].id;
    }

    // 获取特定节点的子节点索引
    int get_child(int u, char c) const {
        return nodes[u].child[c - 'a'];
    }

    // 获取特定节点的字符串 ID
    int get_node_id(int u) const {
        return nodes[u].id;
    }

    int size() const { return id_ptr; }
};

class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        Trie trie;
        int n = original.size();
        // 第一次遍历：建立所有 ID
        for (int i = 0; i < n; ++i) {
            trie.get_id(original[i], true);
            trie.get_id(changed[i], true);
        }

        // 建立邻接表
        int id_count = trie.size();
        vector<vector<pair<int, int>>> adj(id_count);
        vector<int> distinct_starts;
        vector<bool> seen_start(id_count, false);

        for (int i = 0; i < n; ++i) {
            int u = trie.get_id(original[i], false);
            int v = trie.get_id(changed[i], false);
            adj[u].push_back({v, cost[i]});
            if (!seen_start[u]) {
                seen_start[u] = true;
                distinct_starts.push_back(u);
            }
        }

        // 2. 跑 Dijkstra 预处理最短路
        // dists[u][v] 表示 ID u 到 ID v 的最小成本
        vector<vector<long long>> dist(id_count, vector<long long>(id_count, INF));
        
        for (int start_id : distinct_starts) {
            priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
            dist[start_id][start_id] = 0;
            pq.push({0, start_id});

            while (!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[start_id][u]) continue;

                for (auto& [v, w] : adj[u]) {
                    if (dist[start_id][v] > d + w) {
                        dist[start_id][v] = d + w;
                        pq.push({dist[start_id][v], v});
                    }
                }
            }
        }

        // 3. 记忆化搜索
        int m = source.size();
        vector<long long> memo(m, -1);

        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if (i == m) return 0;
            if (memo[i] != -1) return memo[i];

            long long ans = INF;
            // 基础选项：如果字符相同，尝试跳过
            if (source[i] == target[i]) ans = dfs(i + 1);
            // 转换选项：在 Trie 上同步步进
            int sIdx = 0, tIdx = 0;
            for (int j = i; j < m; ++j) {
                sIdx = trie.get_child(sIdx, source[j]);
                tIdx = trie.get_child(tIdx, target[j]);
                if (!sIdx || !tIdx) break; // Trie 路径断开
                int sId = trie.get_node_id(sIdx);
                int tId = trie.get_node_id(tIdx);
                if (sId != -1 && tId != -1) ans = min(ans, dfs(j + 1) + dist[sId][tId]);
            }
            return memo[i] = ans;
        };

        long long result = dfs(0);
        return result >= INF ? -1 : result;
    }
};
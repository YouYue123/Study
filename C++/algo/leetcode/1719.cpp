#include <bits/stdc++.h>
using namespace std;

// 1719. Number Of Ways To Reconstruct A Tree [H]
// LeetCode number-of-ways-to-reconstruct-a-tree

int constexpr INF = 0x3f3f3f3f;
struct Item {
    int val;
    int degree;
};
class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> g; // 邻接表，记录每个点“认识”的所有人（包括祖先和后代）
        unordered_map<int, int> degree_dict; // 记录每个点的度数
        for(auto& p : pairs) {
            int x = p[0], y = p[1];
            degree_dict[x] += 1;
            degree_dict[y] += 1;
            g[x].insert(y);
            g[y].insert(x);
        }
        int nodes_cnt = g.size();
        vector<Item> items;
        for(auto& [val, degree] : degree_dict) {
            items.emplace_back(val, degree);
        }
        sort(items.begin(), items.end(), [&] (auto& a, auto& b) {
            return a.degree < b.degree; // 按度数从小到大排
        });
        int ans = 1;
        // 0 (无解)：没有点能当根（没人认识全员）。 某个子节点的“朋友圈”超出了其父节点的“朋友圈”。
        // 1 (唯一)：每个节点都能找到唯一的“最小上级”覆盖自己的关系网，且度数严格递增。
        // 2 (多种)：存在父子节点地位对等（度数相同）。
        for(int i = 0; i < items.size(); i ++) {
            int u = items[i].val;
            int parent = -1;
            int min_p_degree = INF;
            for(int j = i + 1; j < items.size(); j ++) { // 在度数比自己大的人里找
                int v = items[j].val;
                if(g[u].contains(v)) { // 如果 u 和 v 有关系
                    parent = v; // 第一个遇到的就是“亲爹”
                    break;
                }
            }
            if(parent == -1) {
                // 如果没有爸爸，那它必须是根节点。
                // 根节点必须认识除自己外的所有人，所以度数必须是 nodes_cnt - 1。
                if(items[i].degree != nodes_cnt - 1) return 0;
                continue;
            }
            for(int neighbor : g[u]) {
                if(neighbor == parent) continue;
                // 如果 parent 是 u 的父亲，那么 u 认识的所有人，parent 没理由不认识。
                if(!g[parent].contains(neighbor)) return 0;
            }
            if(items[i].degree == degree_dict[parent]) {
                ans = 2; // 如果父子度数一样，说明他们可以互换位置而关系网不变
            }
        }
        return ans;
    }
};
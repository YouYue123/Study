// 3373. Maximize the Number of Target Nodes After Connecting Trees II [H]
// LeetCode maximize-the-number-of-target-nodes-after-connecting-trees-ii

class Solution {
public:
    void dfs(int node, int parent, int depth, vector<vector<int>>& graph, 
         vector<int>& colors, vector<int>& count) {
        count[depth] += 1;      // 统计当前深度的节点数
        colors[node] = depth;   // 记录当前节点的颜色/深度
        int newDepth = (depth + 1) % 2;  // 下一层的深度（0和1交替）
        
        for(auto& child: graph[node]) {
            if(child == parent) continue;  // 避免回溯到父节点
            dfs(child, node, newDepth, graph, colors, count);
        }
    }
    vector<vector<int>> build(vector<vector<int>>& edges) {
        vector<vector<int>> graph;
        graph.resize(edges.size() + 1);
        for(auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return graph;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // 构建两个图的邻接表
        auto graph1 = build(edges1);
        auto graph2 = build(edges2);
        
        // 初始化颜色数组和计数数组
        vector<int> colors1(edges1.size() + 1, 0);
        vector<int> colors2(edges2.size() + 1, 0);
        vector<int> count1(2, 0);  // 只记录深度0和1的计数
        vector<int> count2(2, 0);
        
        // 执行DFS，从节点0开始，初始深度0
        dfs(0, -1, 0, graph1, colors1, count1);
        dfs(0, -1, 0, graph2, colors2, count2);
        
        // 计算结果
        vector<int> ans(edges1.size() + 1);
        for(int i = 0; i < edges1.size() + 1; i ++) {
            ans[i] = count1[colors1[i]] + max(count2[0], count2[1]);
        }
        return ans;
    }
};
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct LCA
{
    // 记录每个节点的深度（根节点深度为0）
    vector<int> depth;
    // 倍增表，parent[k][u]表示节点u的2^k级祖先
    // eg. 如果k=0，则parent[0][u]是u的直接父节点
    // 如果k=1，则parent[1][u]是u的2级祖先（即u的父节点的父节点）
    // 如果k=2，则parent[2][u]是u的4级祖先（即u的父节点的父节点的父节点的父节点）
    // 以此类推，parent[k][u]表示u的2^k级祖先
    vector<vector<int>> parent;
    // 记录每个节点到根节点的距离（假设边权为1）
    vector<int> dist;
    // n是节点总数
    int n;
    // log_n是倍增法的最大层级
    // 例如，如果n=8，则log_n=3，因为2^3=8
    // 这表示我们需要3层来覆盖所有8个节点
    // 例如，log_n=3时，parent[0][u]是u的直接父节点，parent[1][u]是u的2级祖先，parent[2][u]是u的4级祖先
    // 如果n=16，则log_n=4，因为2^4=16
    // 这表示我们需要4层来覆盖所有16个节点
    int log_n;

    // 构造函数，基于给定的树构建LCA结构
    LCA(unordered_map<int, vector<int>> &tree, int root = 0)
    {
        if (tree.empty())
            return;

        n = tree.size();
        log_n = 0;
        // 找到最大的log_n使得2^log_n <= n
        while ((1 << log_n) <= n)
        {
            log_n++;
        }

        // 初始化数据结构
        depth.assign(n, 0);
        dist.assign(n, 0);
        parent.assign(log_n, vector<int>(n, -1));

        // 使用栈进行DFS遍历
        stack<int> st;
        st.push(root);
        parent[0][root] = -1; // 根节点的直接父节点设为-1

        // 使用栈实现DFS遍历
        // 为每个节点设置：
        // 深度 = 父节点深度 + 1
        // 距离 = 父节点距离 + 1
        // 直接父节点(parent[0][v])
        while (!st.empty())
        {
            int u = st.top();
            st.pop();
            for (auto &v : tree[u])
            {
                if (v == parent[0][u]) // 避免回溯到父节点
                    continue;
                depth[v] = depth[u] + 1;
                dist[v] = dist[u] + 1; // 边权为1，距离=深度
                parent[0][v] = u;      // 设置直接父节点
                st.push(v);
            }
        }

        // 动态规划思想构建倍增表：
        // parent[k][u] = parent[k-1][parent[k-1][u]]
        // 即u的2^k级祖先 = u的2^(k-1)级祖先的2^(k-1)级祖先
        for (int k = 1; k < log_n; ++k)
        {
            for (int u = 0; u < n; ++u)
            {
                if (parent[k - 1][u] != -1)
                {
                    // u的2^k级祖先是u的2^(k-1)级祖先的2^(k-1)级祖先
                    parent[k][u] = parent[k - 1][parent[k - 1][u]];
                }
                else
                {
                    parent[k][u] = -1;
                }
            }
        }
    }

    // 计算两个节点的最近公共祖先
    int lca(int u, int v)
    {
        if (u == v)
            return u;
        if (depth[u] < depth[v]) // 确保u是较深的节点
            swap(u, v);

        // 计算深度差diff
        // 使用二进制分解法：
        // 将diff表示为2的幂次和（如5=4+1）
        // 通过倍增表快速跳跃提升u
        int diff = depth[u] - depth[v];
        for (int k = 0; k < log_n; ++k)
        {
            // 如果diff的第k位为1，则提升u到2^k级祖先
            // 例如，如果diff=5（二进制为101），则提升u到4级祖先和1级祖先
            if (diff & (1 << k))
            {
                u = parent[k][u];
                if (u == -1) // 已经到达根节点
                    break;
            }
        }

        if (u == v) // 如果此时u和v相同，则找到LCA
            return u;

        // 从最高级开始检查：
        // 如果u和v的2^k级祖先不同，则同时提升
        // 如果它们的2^k级祖先相同，则说明找到了LCA
        // 例如，如果u=6，v=5，parent[0][6]=3，parent[0][5]=2
        // 如果k=1时，parent[1][6]=1，parent[1][5]=1，则说明LCA是1
        // 如果k=2时，parent[2][6]=0，parent[2][5]=0，则说明LCA是0
        for (int k = log_n - 1; k >= 0; --k)
        {
            if (parent[k][u] != -1 && parent[k][u] != parent[k][v])
            {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u]; // 返回LCA
    }

    // 计算两个节点之间的距离（假设边权为1）
    int distance(int u, int v)
    {
        int lcaNode = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[lcaNode];
    }
};
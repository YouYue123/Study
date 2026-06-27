# Graph algorithms

Graph utilities as used in practice problems.

| Path | Purpose |
|------|---------|
| [`union_find.cpp`](union_find.cpp) | DSU (union–find) |
| [`scc/kosaraju.cpp`](scc/kosaraju.cpp) | Kosaraju SCC：`comp[u]` 为所属强连通分量编号 |
| [`scc/two_sat.cpp`](scc/two_sat.cpp) | 2-SAT：`TwoSat` 建子句、`solve()` 返回赋值或 UNSAT |
| [`scc/contraction.cpp`](scc/contraction.cpp) | SCC 缩点：`SccContract::build` 得缩点 DAG + 分量权；`max_path_weight()` 为 DAG 最长路（如 Coin Collector） |
| [`path_circuits/hierholzer.cpp`](path_circuits/hierholzer.cpp) | Hierholzer：`Hierholzer` 建无向/有向边；`euler_circuit()` 返回欧拉回路顶点序 |
| [`path_circuits/de_bruijn.cpp`](path_circuits/de_bruijn.cpp) | De Bruijn 图 DFS 生成二进制欧拉迹（`(n-1)` 位状态、`2^n` 条边标 `0/1`） |
| [`path_circuits/hamiltonian_path_cnt.cpp`](path_circuits/hamiltonian_path_cnt.cpp) | 状压 DP 计数 Hamilton 路径（`memo[u][mask]`，0→n−1 访遍所有点） |
| [`path_circuits/warndolf_rule.cpp`](path_circuits/warndolf_rule.cpp) | 8×8 马步 Hamilton 路：Warnsdorff 启发式（按未访问邻居度数排序）+ DFS 回溯 |

`cses/` 题解通常手写图算法；`scc/`、`path_circuits/` 下为可拷贝 snippet，不含 `main`。

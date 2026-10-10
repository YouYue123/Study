# Graph algorithms

Graph utilities as used in practice problems.

| Path | Purpose |
|------|---------|
| [`union_find.cpp`](union_find.cpp) | DSU (union–find) |
| [`scc/kosaraju.cpp`](scc/kosaraju.cpp) | Kosaraju SCC：`comp[u]` 为所属强连通分量编号 |
| [`scc/two_sat.cpp`](scc/two_sat.cpp) | 2-SAT：`TwoSat` 建子句、`solve()` 返回赋值或 UNSAT |
| [`scc/contraction.cpp`](scc/contraction.cpp) | SCC 缩点：`SccContract::build` 得缩点 DAG + 分量权；`max_path_weight()` 为 DAG 最长路 |
| [`path_and_circuit/hierholzer.cpp`](path_and_circuit/hierholzer.cpp) | Hierholzer 欧拉路 / 回路 |
| [`path_and_circuit/de_bruijn_seq.cpp`](path_and_circuit/de_bruijn_seq.cpp) | De Bruijn 图 DFS 生成二进制欧拉迹 |
| [`path_and_circuit/hamiltonian_path.cpp`](path_and_circuit/hamiltonian_path.cpp) | 状压 DP 计数 Hamilton 路径 |
| [`path_and_circuit/warndolf_rule.cpp`](path_and_circuit/warndolf_rule.cpp) | 8×8 马步 Hamilton 路：Warnsdorff + 回溯 |
| [`flow_and_cut/dinic.cpp`](flow_and_cut/dinic.cpp) | Dinic 最大流 |
| [`flow_and_cut/scaling_ford_fulkerson.cpp`](flow_and_cut/scaling_ford_fulkerson.cpp) | Scaling Ford–Fulkerson；含 `get_min_cut_edges` 求最小割边 |

`cses/` 题解通常手写；`scc/`、`path_and_circuit/`、`flow_and_cut/` 下为可拷贝 snippet（多数不含 `main`）。

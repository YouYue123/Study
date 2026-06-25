# Graph algorithms

Graph utilities as used in practice problems.

| Path | Purpose |
|------|---------|
| [`union_find.cpp`](union_find.cpp) | DSU (union–find) |
| [`scc/kosaraju.cpp`](scc/kosaraju.cpp) | Kosaraju SCC：`comp[u]` 为所属强连通分量编号 |
| [`scc/two_sat.cpp`](scc/two_sat.cpp) | 2-SAT：`TwoSat` 建子句、`solve()` 返回赋值或 UNSAT |
| [`scc/contraction.cpp`](scc/contraction.cpp) | SCC 缩点：`SccContract::build` 得缩点 DAG + 分量权；`max_path_weight()` 为 DAG 最长路（如 Coin Collector） |

`cses/` 题解通常手写图算法；`scc/*.cpp` 为可拷贝的 snippet（`#include` 或复制进题解），不含 `main`。

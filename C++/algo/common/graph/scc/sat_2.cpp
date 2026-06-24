#include <bits/stdc++.h>
#include "./kosaraju.cpp"
using namespace std;

// 2-SAT on n variables (1-indexed).
// Literal encoding: +x -> node x, -x -> node x + n  (graph size 2*n + 1, index 0 unused).
//
//   TwoSat sat(m);
//   sat.add_or(sat.lit(a, sign_a != '-'), sat.lit(b, sign_b != '-'));  // (a ∨ b)
//   if (auto ans = sat.solve()) { /* ans[i] = true/false for var i */ }
//   else { /* IMPOSSIBLE */ }
struct TwoSat {
    int n;
    vector<vector<int>> g, rev_g;

    TwoSat(int n) : n(n), g(2 * n + 1), rev_g(2 * n + 1) {}

    int get_neg(int u) { return u <= n ? u + n : u - n; }

    int lit(int var, bool is_true) { return is_true ? var : var + n; }

    void add(int u, int v) {
        g[u].push_back(v);
        rev_g[v].push_back(u);
    }

    // (u ∨ v), u and v are literal nodes
    void add_or(int u, int v) {
        add(get_neg(u), v);
        add(get_neg(v), u);
    }

    void set_value(int var, bool val) {
        if (val) add(var + n, var);
        else add(var, var + n);
    }

    optional<vector<bool>> solve() {
        auto scc = kosaraju(g, rev_g);
        vector<bool> ans(n + 1);
        for (int i = 1; i <= n; i++) {
            int ni = i + n;
            if (scc[i] == scc[ni]) return nullopt;
            ans[i] = scc[i] > scc[ni];
        }
        return ans;
    }
};

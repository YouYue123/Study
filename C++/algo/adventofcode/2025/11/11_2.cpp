#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main() {
    auto start = chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<ull>> nums;
    string line = "";
    unordered_map<string, vector<string>> g;
    long long ans = 0;
    while(getline(cin, line)) {
        stringstream ss(line);
        string from = "";
        getline(ss, from, ':');
        string value_segment;
        getline(ss, value_segment);
        stringstream values_ss(value_segment);
        string val = "";
        while(values_ss >> val) {
            g[from].push_back(val);
        }
    }
    using MemoVal = array<array<ll, 2>, 2>;
    const MemoVal INITIAL_STATE = {
        {{-1LL, -1LL}, // Row 0: {-1, -1}
         {-1LL, -1LL}}  // Row 1: {-1, -1}
    };
    unordered_map<string, MemoVal> memo;
    // map<tuple<string, bool, bool>, ll> memo;
    auto dfs = [&] (this auto&& dfs, string cur, bool fft, bool dac) -> ll {
        if (cur == "out") return (fft && dac) ? 1 : 0;
        ll ans = 0;
        if (memo.count(cur) && memo[cur][fft][dac] != -1) {
            return memo[cur][fft][dac];
        } else {
            memo[cur] = INITIAL_STATE;
        }
        for (auto &nx : g[cur]) {
            if (nx == "fft") ans += dfs(nx, true, dac);
            else if (nx == "dac") ans += dfs(nx, fft, true);
            else ans += dfs(nx, fft, dac);
        }
        return memo[cur][fft][dac] = ans;
    };
    cout << dfs("svr", false, false) << endl;
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "runtime: " << duration.count() << " nanoseconds" << endl;
}
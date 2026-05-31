#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct Ops {
    int idx;
    int from;
    int to;
};
vector<Ops> ops;

auto dfs (int idx, int from, int to) {
    if(idx == 0) return;
    int spare = 6 - from - to;
    dfs(idx - 1, from, spare);
    ops.emplace_back(idx, from, to);
    dfs(idx - 1, spare, to);
};
void solve()
{
    int n;
    cin >> n;

    dfs(n, 1, 3);

    cout << ops.size() << endl;

    for(auto& op : ops) {
        cout << op.from << " " << op.to << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    auto ask = [&] (int u, int v, int d) {
        cout << "? " << u + 1 << " " << v + 1 << " " << d << endl;
        cout.flush();
        int verdict;
        cin >> verdict;
        return verdict;
    };

    int dist = 0, p1 = 0;
    for(int v = 1; v < n && dist < n - 1; v ++) {
        if(ask(0, v, dist + 1) == 0) continue;
        p1 = v;
        dist += 1;
        while(dist < n - 1 && ask(0, v, dist + 1) == 1) dist += 1;
    }
    int p2 = 0;
    for(int v = 0; v < n && dist < n - 1; v ++) {
        if(ask(p1, v, dist + 1) == 0) continue;
        p2 = v;
        dist += 1;
        while(dist < n - 1 && ask(p1, v, dist + 1) == 1) dist += 1;
    }
    cout << "! " << p1 + 1 << " " << p2 + 1 << " " << dist << endl;
    cout.flush();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
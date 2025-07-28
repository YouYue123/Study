#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> parent(n + 1, 0), depth(n + 1, 0);
        vector<ll> P(n + 1), pref_min(n + 1), pref_max(n + 1), threat(n + 1);

        parent[1] = 0;
        depth[1] = 0;
        P[1] = a[1];
        threat[1] = a[1];
        pref_min[1] = min(0LL, P[1]);
        pref_max[1] = max(0LL, P[1]);

        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (v == parent[u])
                    continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                ll b = (depth[v] % 2 == 0 ? a[v] : -a[v]);
                P[v] = P[u] + b;

                if (depth[v] % 2 == 0)
                {
                    threat[v] = P[v] - pref_min[u];
                }
                else
                {
                    threat[v] = pref_max[u] - P[v];
                }
                pref_min[v] = min(pref_min[u], P[v]);
                pref_max[v] = max(pref_max[u], P[v]);

                q.push(v);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << threat[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}

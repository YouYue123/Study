#include <iostream>
#include <unordered_map>
#include <vector>
#include <tuple>
using namespace std;
using ll = long long;

// 自定义 pair 的哈希函数
struct PairHash
{
    template <typename T1, typename T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ (hash2 << 1); // 组合哈希
    }
};

// 自定义 tuple 的哈希函数（C++17 支持）
struct TupleHash
{
    template <typename... Args>
    size_t operator()(const tuple<Args...> &t) const
    {
        size_t seed = 0;
        // 使用折叠表达式展开 tuple
        apply([&seed](const Args &...args)
              { ((seed ^= hash<Args>{}(args) + 0x9e3779b9 + (seed << 6) + (seed >> 2)), ...); }, t);
        return seed;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ll ans = 0;

    // 使用 unordered_map + 自定义哈希
    unordered_map<pair<ll, int>, int, PairHash> c12, c13, c23;
    unordered_map<tuple<int, int, int>, int, TupleHash> c3;

    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }

    int x = a[0], y = a[1];
    for (int i = 2; i < n; ++i)
    {
        int z = a[i];
        auto key12 = make_pair(x, y);
        auto key13 = make_pair(x, z);
        auto key23 = make_pair(y, z);
        auto key123 = make_tuple(x, y, z);

        ans += c12[key12] + c13[key13] + c23[key23] - 3 * c3[key123];

        c12[key12]++;
        c13[key13]++;
        c23[key23]++;
        c3[key123]++;

        x = y;
        y = z;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for(int i = 0; i < n; i ++) cin >> a[i];
    sort(a.begin(), a.end(), greater<>());
    vector<int> b;
    vector<int> c;
    b.push_back(a[0]);
    c.push_back(a[0]);
    unordered_set<int> candidate;
    for(int i = 1; i < n; i ++) candidate.insert(i);
    for(int i = 1; i < n; i ++) {
        int max_val = 0, max_idx = -1;
        for(auto idx : candidate) {
            int val = gcd(a[idx], c.back());
            if(max_val < val) {
                max_val = val;
                max_idx = idx;
            }
        }
        candidate.erase(max_idx);
        b.push_back(a[max_idx]);
        c.push_back(max_val);
    }
    for(int val : b) {
        cout << val << " ";
    } 
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
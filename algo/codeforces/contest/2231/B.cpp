#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> next_greater(n, INF);
    stack<ll> st;
    for(int i = 0; i < n; i ++) {
        while(!st.empty() && a[st.top()] < a[i]) {
            next_greater[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }
    ll add = 0;
    for(int i = 1; i < n;i ++) {
        if(a[i - 1] > a[i]) {
            add = max(add, a[i - 1] - a[i]);
        }
    }
    for(int i = 1; i < n; i ++) {
        if(a[i - 1] > a[i]) a[i] += add;
    }
    // for(auto& item : a) {
    //     cout << item << " ";
    // }
    // cout << endl;
    // cout << "here" << endl;
    for(int i = 0; i < n - 1; i ++) {
        if(a[i] > a[i + 1]) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
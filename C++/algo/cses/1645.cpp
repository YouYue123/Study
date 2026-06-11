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
    stack<ll> st;
    vector<int> ans(n, 0);
    for(int i = n - 1; i >= 0; i --) {
        while(!st.empty() && a[st.top()] > a[i]) {
            ans[st.top()] = i + 1;
            st.pop();
        }
        st.push(i);
    }
    for(auto& item : ans) cout << item << " ";
    cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
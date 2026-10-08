#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans;
    stack<int> st;
    vector<int> printed(n + 1, false);
    int cnt = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            st.push(i + 1);
        } else if(s[i] == '2') {
            if(!st.empty()) {
                printed[st.top()] = true;
                st.pop();
            } else {
                printed[i + 1] = true;
            }
            cnt += 1;
        } else if(s[i] == '3'){
            printed[i + 1] = true;
            cnt += 1;
        }
    }
    cout << n - cnt << endl;
    for(int i = 1; i <= n; i ++) {
        if(!printed[i]) cout << i << " ";
    }
    cout << endl;
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
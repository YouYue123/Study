#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // MurmurHash3 mixed-in，guarantee even distribution
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        // Add Salt with system timestamp
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve()
{
    int n;
    char c;
    cin >> n >> c;
    string s;
    cin >> s;
    assert(s.size() == n);
    // if(c == 'g') {
    //     cout << 0 << endl;
    //     return;
    // }
    string new_s = s + s;
    ll prev = -1, ans = -1;
    for(int i = 0; i < 2 * n; i ++) {
        if(new_s[i] == c && prev == -1) {
            prev = i;
        }
        if(new_s[i] == 'g' && prev != -1) {
            // cout << "found g at: " << i << " prev at: " << prev << endl; 
            ans = max(ans, i - prev);
            prev = -1;
        } 
    }
    cout << ans << endl;
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
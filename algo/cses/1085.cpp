#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, k;
    cin >> n >> k;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];
    vector<ll> presum(n + 1, 0LL);
    for(int i = 0; i < n; i ++) presum[i + 1] = presum[i] + a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll min_val = *min_element(a.begin(), a.end());
    auto is_valid = [&] (ll max_sum) -> bool {
        ll cur_sum = 0;
        int cnt = 0;
        int i = 0;
        while(i < n) {
            if(a[i] > max_sum) return false;
            if(cur_sum + a[i] <= max_sum) {
                cur_sum += a[i];
            } else {
                cnt += 1;
                cur_sum = a[i];
            }
            i += 1;
        }
        if(cur_sum != 0) cnt += 1;
        // for(int i = 0; i < n; i ++) {
        //     if(a[i] > max_sum) return false;
        //     cur_sum += a[i];
        //     if(cur_sum > max_sum) {
        //         cnt += 1;
        //         cur_sum = a[i];
        //     }
        // }
        
        // cout << "cnt: " << cnt << endl;
        return cnt <= k;
    };
    // cout << is_valid(7) << endl;
    ll left = min_val - 1, right = sum + 1;
    while(left + 1 < right) {
        ll mid = left + (right - left) / 2;
        if(is_valid(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << left + 1 << endl;
    // vector memo(k + 1, vector(n + 1, INF));
    // memo[k][n] = 0;
    // for(int cnt = k - 1; cnt >= 0; cnt --) {
    //     ll sum = 0;
    //     for (int i = 0; i < n; i ++) {
    //         // deque<ll> q;
    //         // while(!q.empty() && q.back() < )
    //         // sum += a[i];
    //         // memo[cnt][i] = min(
    //         //     memo[cnt][i],
    //         //     max(sum, memo[cnt + 1][i + 1])
    //         // );
    //         // if(q.front() )
    //         ll sum = 0;
    //         for(int j = i; j < n; j ++) {
    //             sum += a[j];
    //             // cout << "i: " << i << " j: " << j << " cnt: " << cnt << endl;
    //             memo[cnt][i] = min(
    //                 memo[cnt][i],
    //                 max(sum, memo[cnt + 1][j + 1])
    //             );
    //         }
    //     }
    // }
    // cout << memo[0][0] << endl;

    // auto dfs = [&] (this auto&& dfs, int i, int cnt) {
    //     if(i == n && cnt == k) return 0LL;
    //     if(i == n || cnt == k) return INF;
    //     if(memo[cnt][i] != INF) return memo[cnt][i];
    //     ll sum = 0, ans = INF;
    //     for(int j = i; j < n; j ++) {
    //         sum += a[j];
    //         ans = min(
    //             ans,
    //             max(sum, dfs(j + 1, cnt + 1))
    //         );
    //     }
    //     return memo[cnt][i] = ans;
    // };
    // cout << dfs(0, 0) << endl;
   
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
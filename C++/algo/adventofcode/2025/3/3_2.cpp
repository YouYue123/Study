#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ull POW10[] = {
    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 
    1000000000, 10000000000ULL, 100000000000ULL, 1000000000000ULL
};
int main()
{
    auto start = chrono::high_resolution_clock::now();
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string line;
    ull ans = 0;
    while(getline(cin, line)) {
        int n = line.size();
        stack<int> st;
        int k = 12;
        for(int i = 0; i < n; i ++) {
            int num = line[i] - '0';
            int remain = n - i;
            while(!st.empty() && st.top() < num && remain + st.size() - 1 >= k) {
                st.pop();
            }
            if(st.size() < 12) st.push(num);
        }
        ull cur = 0;
        int i = 0;
        while(!st.empty()) {
            cur = st.top() * POW10[i] + cur; st.pop();
            i += 1;
        }
        ans += cur;
        // DP:
        // ull curMax = 0;
        // vector memo(n + 1,vector(13, LLONG_MAX));
        // auto dfs = [&] (this auto&& dfs, int i, int cnt) -> ll {
        //     if(cnt == 0) return 0LL;
        //     if(i == n  || (n - i) < cnt) return -1LL;
        //     if(memo[i][cnt] != LLONG_MAX) return memo[i][cnt]; 
        //     ll curMax = dfs(i + 1, cnt);
        //     ll nextVal = dfs(i + 1, cnt - 1);
        //     if(nextVal >= 0) {
        //         ll num = line[i] - '0';
        //         ll curPow = POW10[cnt - 1];
        //         ll contrib = num * curPow;
        //         curMax = max(
        //             curMax,
        //             contrib + nextVal
        //         );
        //     }
        //     // cout << i << " " << cnt << " " <<  curMax << endl;
        //     return memo[i][cnt] = curMax;
        // };
        // ans += dfs(0, 12);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "ans:" << ans << endl;
    cout << "runtime: " << duration.count() << " microseconds" << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    int n;
    cin >> n;
    if(n == 3 || n == 2) {
        cout <<  "NO SOLUTION" << endl;
        return;
    }
    int left = 0, right = 0;
    if(n % 2 == 0) {
        left = 1;
        right = n / 2 + 1;
    } else {
        left = 2;
        right = n / 2 + 2;
    }
    while(right <= n) {  
        cout << right << " " << left << " ";
        left += 1;
        right += 1;
    }
    if(n % 2 == 1) cout << 1;
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
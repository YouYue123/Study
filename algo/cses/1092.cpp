#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

void solve()
{
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if(sum % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    vector<int> set_1, set_2;
    if(n % 2 == 1) {
        set_2.push_back(n);
    }
    int left = 1, right = n % 2 == 0 ? n : n - 1;
    while(left < right) {
        set_1.push_back(left);
        set_1.push_back(right);
        left += 2;
        right -= 2;
    }
    left = 2, right = n % 2 == 0 ? n - 1 : n - 2;
    while(left < right) {
        set_2.push_back(left);
        set_2.push_back(right);
        left += 2;
        right -= 2;
    }
    cout << "YES" << endl;
    cout << set_1.size() << endl;
    for(int item: set_1) {
        cout << item << " ";
    }
    cout << endl;
    cout << set_2.size() << endl;
    for(int item : set_2) {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
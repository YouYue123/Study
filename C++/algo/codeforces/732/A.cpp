#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int k, r;
    cin >> k >> r;
    for(int i = 1; i <= 10; i ++) {
        if(k * i % 10 == r || k * i % 10 == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << 10 << endl;
}
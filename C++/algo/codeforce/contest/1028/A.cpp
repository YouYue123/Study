#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <limits>
#include <functional>
#include <deque>
#include <unordered_set>
#include <map>
using namespace std;
using ll = long long;
using ull = unsigned long long;

void solve()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long g = min(a ,c);
    long long f = min(b, d);
    if(f >= g + 1) cout << "Flower" << endl;
    else cout << "Gellyfish" << endl;
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
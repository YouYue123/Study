#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <unordered_map>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int target = stoi(s);
        bool found = false;
        int sq = (int)sqrt(target);
        if (sq * sq != target)
        {
            cout << -1 << endl;
            continue;
        }
        cout << 0 << " " << sq << endl;
    }
}
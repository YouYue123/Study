#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int curMax = INT_MIN;
        int curMin = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            curMax = max(curMax, a[j]);
            curMin = min(curMin, a[j]);
        }
        cout << curMax - curMin << endl;
    }

    return 0;
}
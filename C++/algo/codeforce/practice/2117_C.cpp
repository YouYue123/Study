#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n; 
        vector<int> a(n);
        unordered_map<int, int> dict;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            dict[a[i]] += 1;
        }
        int ans = 1;
        unordered_set<int> prev;
        prev.insert(a[0]);
        unordered_set<int> cur;
        for(int i = 1; i < n; i ++) {
            if(prev.contains(a[i])) prev.erase(a[i]);
            cur.insert(a[i]);
            if(prev.empty()) {
                ans += 1;
                swap(prev, cur);
            }
        }
        cout << ans << endl;
    }
}

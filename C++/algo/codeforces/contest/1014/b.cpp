#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <stack>
using namespace std;



struct DSU
{
    int n;
    vector<int> parent, rank;

    DSU(int n) : n(n), parent(n), rank(n, 0)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find_set(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        DSU dsu(2 * n);

        for (int i = 1; i < n; i++)
        {
            dsu.union_set(i, n + (i - 1));
            dsu.union_set(n + i, i - 1);
        }

        vector<long long> compCount1(2 * n, 0LL);
        vector<long long> compCountA(2 * n, 0LL);
        vector<long long> compCountB(2 * n, 0LL);

        for (int i = 0; i < n; i++)
        {
            int rootA = dsu.find_set(i);
            compCountA[rootA]++;
            if (a[i] == '1')
            {
                compCount1[rootA]++;
            }

            int rootB = dsu.find_set(n + i);
            compCountB[rootB]++;
            if (b[i] == '1')
            {
                compCount1[rootB]++;
            }
        }

        bool possible = true;
        for (int i = 0; i < 2 * n; i++)
        {
            if (dsu.find_set(i) == i)
            {
                long long cntA = compCountA[i];
                long long cntB = compCountB[i];
                long long cnt1 = compCount1[i];
                if (cnt1 > cntB)
                {
                    possible = false;
                    break;
                }
            }
        }

        cout << (possible ? "YES\n" : "NO\n");
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/dsu/

struct UF
{
    vector<int> parent; // parent[i] stores the parent of element i, or i itself if it's a root
    int n;              // Total number of elements

    UF(int size) : n(size), parent(size)
    {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }
    int findRoot(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findRoot(parent[x]);
    }

    void unite(int x, int y)
    {
        int rootX = findRoot(x);
        int rootY = findRoot(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }

    bool connected(int x, int y)
    {
        return findRoot(x) == findRoot(y);
    }

    int size()
    {
        return n;
    }
};
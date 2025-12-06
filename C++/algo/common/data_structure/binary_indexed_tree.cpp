#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/fenwick/
// Binary Indexed Tree (also known as Fenwick Tree) data structure
struct BIT
{
    vector<int> tree;
    BIT(int N)
    {
        // (element count + 1, since indexing starts from 1)
        tree.assign(N + 1, 0);
    }

    int lowbit(int i)
    {
        return i & (-i);
    }

    void add(int index, int delta)
    {
        while (index < (int)tree.size())
        {
            tree[index] += delta;
            index += lowbit(index); // Move to parent node
        }
    }

    int query(int index)
    {
        int ans = 0;
        while (index > 0)
        {
            ans += tree[index];
            index -= lowbit(index); // Move to the previous node
        }
        return ans;
    }
};
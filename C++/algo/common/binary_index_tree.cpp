#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/fenwick/
// Binary Indexed Tree (also known as Fenwick Tree) data structure
struct BIT
{
    vector<int> tree; // Array storing the binary indexed tree

    // Constructor, initializes the binary indexed tree
    // Parameter N: Size of the binary indexed tree (usually element count + 1, since indexing starts from 1)
    BIT(int N)
    {
        tree.assign(N + 1, 0); // Allocate N+1 spaces and initialize to 0
    }

    // Calculate the lowbit value, which is the value represented by the lowest set bit
    // Example: lowbit(6)=2 (6 in binary is 110)
    int lowbit(int i)
    {
        return i & (-i); // Bit manipulation trick: bitwise AND of i and its negative value
    }

    // Add value to the specified position in the binary indexed tree
    // Parameter index: Position to update (starting from 1)
    // Parameter val: Value to add
    void add(int index, int val)
    {
        // Starting from index, update all related nodes upward
        while (index < (int)tree.size())
        {
            tree[index] += val;     // Add val to current node
            index += lowbit(index); // Move to parent node
        }
    }

    // Query prefix sum (sum of elements from 1 to index)
    // Parameter index: End position of the query
    // Return value: Sum of the first index elements
    int query(int index)
    {
        int ans = 0; // Initialize result to 0

        // Starting from index, accumulate values of all related nodes downward
        while (index > 0)
        {
            ans += tree[index];     // Accumulate current node's value
            index -= lowbit(index); // Move to the previous node that needs to be accumulated
        }
        return ans; // Return accumulated result
    }
};
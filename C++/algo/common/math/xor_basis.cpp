#include <bits/stdc++.h>
using namespace std;
class XorBasis
{
    vector<int> b;  
public:
    XorBasis(int n) : b(n) {}
    void insert(uint32_t x)
    {
        while (x)
        {
            int i = bit_width(x) - 1;
            if (b[i] == 0)
            {
                b[i] = x;
                return;
            }
            x ^= b[i];
        }
    }

    uint32_t max_xor()
    {
        uint32_t res = 0;
        for (int i = b.size() - 1; i >= 0; i--)
        {
            res = max(res, res ^ b[i]);
        }
        return res;
    }
};

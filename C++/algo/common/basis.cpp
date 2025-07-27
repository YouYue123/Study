#include <bits/stdc++.h>
using namespace std;
class XorBasis {
    vector<uint32_t> b;

public:
    XorBasis(int n) : b(n) {}

    void insert(uint32_t x) {
        while (x) {
            int i = bit_width(x) - 1; // x 的最高位
            if (b[i] == 0) { // x 和之前的基是线性无关的
                b[i] = x; // 新增一个基，最高位为 i
                return;
            }
            x ^= b[i]; // 保证参与 max_xor 的基的最高位是互不相同的，方便我们贪心
        }
        // 正常循环结束，此时 x=0，说明一开始的 x 可以被已有基表出，不是一个线性无关基
    }

    uint32_t max_xor() {
        uint32_t res = 0;
        // 从高到低贪心：越高的位，越必须是 1
        // 由于每个位的基至多一个，所以每个位只需考虑异或一个基，若能变大，则异或之
        for (int i = b.size() - 1; i >= 0; i--) {
            res = max(res, res ^ b[i]);
        }
        return res;
    }
};

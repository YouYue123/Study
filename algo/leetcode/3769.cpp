#include <bits/stdc++.h>
using namespace std;

// 3769. Sort Integers by Binary Reflection [E]
// LeetCode sort-integers-by-binary-reflection

class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        auto getReverse = [&] (int x) {
            int ans = 0;
            while(x > 0) {
                int lsb = x & 1;
                ans <<= 1;
                ans |= lsb;
                x >>= 1;
            }
            return ans;
        };
        sort(nums.begin(), nums.end(), [&] (int a, int b) {
                int ra = getReverse(a);
                int rb = getReverse(b);
                if(ra == rb) return a < b;
                return ra < rb;
        });
        return nums;
    }
};
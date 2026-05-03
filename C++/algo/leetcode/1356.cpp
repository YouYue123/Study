// 1356. Sort Integers by The Number of 1 Bits [E]
// LeetCode sort-integers-by-the-number-of-1-bits

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&] (int a, int b) {
            int bitACnt = __builtin_popcount(a);
            int bitBCnt = __builtin_popcount(b);
            if(bitACnt == bitBCnt) return a < b;
            return  bitACnt < bitBCnt;
        });
        return arr;
    }
};
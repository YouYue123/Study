// 201. Bitwise AND of Numbers Range [M]
// LeetCode bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left < right) {
            cout << left << " " << right << endl;
            left >>= 1;
            right >>= 1;
            shift += 1;
        }
        return left << shift;
    }
};
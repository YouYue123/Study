// 2154. Keep Multiplying Found Values by Two [E]
// LeetCode keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& nums, int k) {
        int bits = 0;                 // used as a set
        for (auto& n : nums) {
            if (n % k != 0) continue; // ignore non integers
            n = n / k;                // normalize n
            if ((n & (n - 1)) == 0)   // power of two check
                bits |= n;            // store pow2 to bits
        }
        int d = ~bits;                // flip bits
        return k * (d & -d);          // find missing power * k
    }
};
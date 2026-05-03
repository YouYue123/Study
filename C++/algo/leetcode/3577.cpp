// 3577. Count the Number of Computer Unlocking Permutations [M]
// LeetCode count-the-number-of-computer-unlocking-permutations

int MOD = 1e9 + 7;

class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        if (n == 0) return 0;
        
        int c0 = complexity[0];
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= c0) {
                return 0;
            }
        }
        long long result = 1;
        for (int i = 1; i < n; i++)  result = (result * i) % MOD;
        
        return (int)result;
    }
};
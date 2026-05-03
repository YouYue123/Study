// 1137. N-th Tribonacci Number [E]
// LeetCode n-th-tribonacci-number

class Solution {
public:
    unordered_map<int, int> dict;
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;
        if(dict.contains(n)) return dict[n];
        return dict[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
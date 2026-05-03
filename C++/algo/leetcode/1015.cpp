// 1015. Smallest Integer Divisible by K [M]
// LeetCode smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k % 2 == 0) return -1;
        long long n = 1;
        int ans = 1;
        unordered_map<int, bool> visited;
        while(n % k != 0) {
            if(visited[n]) return -1;
            visited[n] = true;
            n = ((n * 10) + 1) % k;
            ans += 1;
        }
        return ans;
    }
};
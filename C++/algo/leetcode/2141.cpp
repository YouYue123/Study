// 2141. Maximum Running Time of N Computers [H]
// LeetCode maximum-running-time-of-n-computers

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = reduce(batteries.begin(), batteries.end(), 0LL);
        long long left = 0, right = total / n + 1;
        while(left < right) {
            long long mid = left + (right - left) / 2;
            long long sum = 0;
            for(long long b: batteries) sum += min(b, mid);
            if(n * mid <= sum) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};
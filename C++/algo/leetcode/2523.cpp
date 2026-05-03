// 2523. Closest Prime Numbers in Range [M]
// LeetCode closest-prime-numbers-in-range

class Solution {
public:
    bool isPrime(int num) {
        if(num == 1) return false;
        if(num == 2 || num == 3) return true;
        if(num % 2 == 0) return false;
        for(int i = 3; i <= sqrt(num); i += 2) {
            if (num % i == 0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        int num1 = -1;
        int num2 = -1;
        int minDistance = INT_MAX;
        int pre = -1;
        for (int i = left; i <= right; i ++) {
            if(isPrime(i)) {
                // cout << i << endl;
                if(pre != -1) {
                    int curDiff = i - pre;
                    if(curDiff < minDistance) {
                        num1 = pre;
                        num2 = i;
                        minDistance = curDiff;
                    }
                }
                pre = i;
            }
        }
        if(num1 == -1 || num2 == -1) {
            return {-1, -1};
        }
        return {num1, num2};
    }
};
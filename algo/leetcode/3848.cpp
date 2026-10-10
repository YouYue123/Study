#include <bits/stdc++.h>
using namespace std;

// 3848. Check Digitorial Permutation [M]
// LeetCode check-digitorial-permutation



class Solution {
    int fact[10] = {0};
public:
    Solution () {
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2; i <= 9; i ++) {
            fact[i] = fact[i - 1] * i;
            cout << fact[i] << " ";
        }
        cout << endl;
    }
    bool isDigitorialPermutation(int n) {
        int cnt[10] = {0};
        // if(n == 40558) return true;
        long long sum = 0;
        while(n > 0) {
            int digit = n % 10;
            n /= 10;
            // cout << digit << " " << fact[digit] << endl;
            sum += fact[digit];
            cnt[digit] += 1;
        }
        cout << sum << endl;
        while(sum > 0) {
            int digit = sum % 10;
            sum /= 10;
            cnt[digit] -= 1;
        }
        for(int i = 0; i <= 9; i ++) {
            if(cnt[i] != 0) return false;
        }
        return true;
    }
};
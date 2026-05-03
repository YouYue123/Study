#include <bits/stdc++.h>
using namespace std;

// 2081. Sum of k-Mirror Numbers [H]
// LeetCode sum-of-k-mirror-numbers

const int MAX_N = 30;
vector<long long> ans[10];
bool isKPalindrome(long long x, int k) {
    if(x % k == 0) return false;
    int rev = 0;
    while(rev < x / k) {
        rev = rev * k + x % k;
        x /= k;
    }
    return rev == x || rev == x / k;
}
bool doPalindrome(long long x) {
    bool done = true;
    for(int k = 2; k <= 9; k ++) {
        if(ans[k].size() < MAX_N && isKPalindrome(x, k)) {
            ans[k].push_back(x);
        }
        if(ans[k].size() < MAX_N) done = false;
    }
    if(!done) return false;
    for(int k = 2; k < 10; k ++) {
        partial_sum(ans[k].begin(), ans[k].end(), ans[k].begin());
    }
    return true;
}
auto init = [] () {
    for(int base = 1;;base *= 10) {
        for(int i = base; i < base * 10; i ++) {
            long long x = i;
            for(int t = i / 10; t > 0; t /= 10) {
                x = x * 10 + t % 10;
            }
            if(doPalindrome(x)) return 0;
        }
        for(int i = base; i < base * 10 ; i ++) {
            long long x = i;
            for(int t = i; t > 0; t /= 10) {
                x = x * 10 + t % 10;
            }
            if(doPalindrome(x)) return 0;
        }
    }
}();
class Solution {
public:
    long long kMirror(int k, int n) {
        return ans[k][n - 1];
    }
};
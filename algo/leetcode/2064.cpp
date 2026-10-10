#include <bits/stdc++.h>
using namespace std;

// 2064. Minimized Maximum of Products Distributed to Any Store [M]
// LeetCode minimized-maximum-of-products-distributed-to-any-store

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        auto isValid = [&](int x) {
            int cnt = 0;
            for(int q : quantities) {
                cnt += ceil((double)q / x);
                if(cnt > n) return false;
            }
            return cnt <= n;
        };
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end()) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
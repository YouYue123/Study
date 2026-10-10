#include <bits/stdc++.h>
using namespace std;

// 2086. Minimum Number of Food Buckets to Feed the Hamsters [M]
// LeetCode minimum-number-of-food-buckets-to-feed-the-hamsters

class Solution {
public:
    int minimumBuckets(string h) {
        int n = h.size();
        int cnt = 0;
        for(int i = 0; i < n; i ++) {
            if(h[i] == 'H') {
                if(i > 0 && h[i - 1] == 'T') {
                    continue;
                }
                if(i < n && h[i + 1] == '.') {
                    h[i + 1] = 'T';
                    cnt += 1;
                } else if(i > 0 && h[i - 1] == '.') {
                    h[i - 1] = 'T';
                    cnt += 1;
                } else {
                    return -1;
                }
            }
        }
        return cnt;
    }
};
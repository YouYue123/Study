#include <bits/stdc++.h>
using namespace std;

// 1151. Minimum Swaps to Group All 1's Together [M]
// LeetCode minimum-swaps-to-group-all-1s-together

class Solution {
public:
    int minSwaps(vector<int>& data) {
        int left = 0, right = 0;
        int k = 0;
        for(int num : data) {
            if(num == 1) k += 1;
        }
        int ans = INT_MAX;
        int zeroCount  = 0;
        while(right < data.size()) {
            if(data[right] == 0) zeroCount += 1;
            if(right - left + 1 > k) {
                if(data[left] == 0) zeroCount -= 1;
                left += 1;
            }
            if(right - left + 1 == k) ans = min(ans, zeroCount);
            right += 1;
        }
        return ans;
    }
};
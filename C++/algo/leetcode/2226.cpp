#include <bits/stdc++.h>
using namespace std;

// 2226. Maximum Candies Allocated to K Children [M]
// LeetCode maximum-candies-allocated-to-k-children

class Solution {
public:
    int isValid(int mid, vector<int>& candies, long long k) {
        for(int c : candies) {
            k -= c / mid;
        }
        return k <= 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int left = 1, right = *max_element(candies.begin(), candies.end()) + 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(isValid(mid, candies, k)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
};
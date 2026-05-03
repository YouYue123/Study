#include <bits/stdc++.h>
using namespace std;

// 1442. Count Triplets That Can Form Two Arrays of Equal XOR [M]
// LeetCode count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, cnt = 0;
        int ans = 0;
        unordered_map<int, int> dict, total;
        for(int i = 0; i < arr.size(); i ++) {
            sum ^= arr[i];
            if(dict.contains(sum)) {
                ans += i * dict[sum] - total[sum];
            }
            dict[sum ^ arr[i]] += 1;
            total[sum ^ arr[i]] += i;
        }
        return ans;
    }
};
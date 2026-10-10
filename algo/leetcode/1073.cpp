#include <bits/stdc++.h>
using namespace std;

// 1073. Adding Two Negabinary Numbers [M]
// LeetCode adding-two-negabinary-numbers

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int p = 0, carry = 0;
        vector<int> ans;
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        while(p < arr1.size() || p < arr2.size() || carry != 0) {
            int d1 = p < arr1.size() ? arr1[p] : 0;
            int d2 = p < arr2.size() ? arr2[p] : 0;
            int sum = d1 + d2 + carry;
            if(sum >= 2) {
                carry = -1;
                ans.push_back(sum - 2);
            } else if(sum < 0) {
                carry = 1;
                ans.push_back(sum + 2);
            } else {
                carry = 0;
                ans.push_back(sum);
            }
            p += 1;
        }
        while(ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
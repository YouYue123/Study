#include <bits/stdc++.h>
using namespace std;

// 932. Beautiful Array [M]
// LeetCode beautiful-array

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if(n == 1) return {1};
        vector<int> ans;
        int oddCnt = (n + 1) / 2;
        int evenCnt = n / 2;
        for(int x : beautifulArray(oddCnt)) {
            ans.push_back(x * 2 - 1);
        }
        for(int x : beautifulArray(evenCnt)) {
            ans.push_back(x * 2);
        }
        return ans;
    }
};
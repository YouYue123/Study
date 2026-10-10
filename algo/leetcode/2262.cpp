#include <bits/stdc++.h>
using namespace std;

// 2262. Total Appeal of A String [H]
// LeetCode total-appeal-of-a-string

class Solution {
public:
    long long appealSum(string s) {
        int n = s.size();
        long long ans = 0;
        vector<int> last(26, -1);
        int sum = 0;
        for(int i = 0; i < n; i ++) {
            int c = s[i] - 'a';
            sum += i - last[c];
            last[c] = i;
            ans += sum;
        }
        return ans;
    }
};
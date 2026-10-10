#include <bits/stdc++.h>
using namespace std;

// 3335. Total Characters in String After Transformations I [M]
// LeetCode total-characters-in-string-after-transformations-i

class Solution {
public:
    int mod = 1e9 + 7;
    int lengthAfterTransformations(string s, int t) {
        vector<long long> count(26, 0); // Count of each character (a to z)
        
        for (char c : s) count[c - 'a']++;
        for (int i = 0; i < t; i++) {
            vector<long long> nextCount(26, 0);
            for (int j = 0; j < 25; j++) nextCount[j + 1] = count[j];
            nextCount[0] = (nextCount[0] + count[25]) % mod; // z -> a
            nextCount[1] = (nextCount[1] + count[25]) % mod; // z -> b
            count = nextCount;
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + count[i]) % mod;
        }
        
        return ans;
    }
};
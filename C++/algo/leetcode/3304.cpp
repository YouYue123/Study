#include <bits/stdc++.h>
using namespace std;

// 3304. Find the K-th Character in String Game I [E]
// LeetCode find-the-k-th-character-in-string-game-i

class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;
        int t;
        while(k != 1) {
            t = __lg(k);
            if((1 <<t) == k) t --;
            k = k - (1 << t);
            ans += 1;
        }
        return 'a' + ans;
    }
};
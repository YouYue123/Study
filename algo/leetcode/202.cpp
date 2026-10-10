#include <bits/stdc++.h>
using namespace std;

// 202. Happy Number [E]
// LeetCode happy-number

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> dict;
        while(n != 1) {
            if(dict.contains(n)) return false;
            dict.insert(n);
            int temp = n;
            int sum = 0;
            while(temp) {
                sum += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
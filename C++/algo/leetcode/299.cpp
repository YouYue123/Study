#include <bits/stdc++.h>
using namespace std;

// 299. Bulls and Cows [M]
// LeetCode bulls-and-cows

class Solution {
public:
    string getHint(string secret, string guess) {
        string ans = "";
        int bullCount = 0;
        int cowCount = 0;
        unordered_map<char, int> dict;
        for(char c : secret) dict[c] += 1;
        for(int i = 0; i < secret.size(); i ++) {
            char sc = secret[i];
            char gc = guess[i];
            if(sc == gc) {
                bullCount += 1;
                dict[sc] -= 1;
            }
        }
        for(int i = 0; i < secret.size(); i ++) {
            char sc = secret[i];
            char gc = guess[i];
            if(sc != gc && dict[gc] > 0) {
                // cout << dict[gc] << endl;
                cowCount += 1;
                dict[gc] -= 1;
            }
        }
         
        
        return to_string(bullCount) + "A" + to_string(cowCount) + "B";
    }
};
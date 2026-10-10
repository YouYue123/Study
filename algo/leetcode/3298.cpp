#include <bits/stdc++.h>
using namespace std;

// 3298. Count Substrings That Can Be Rearranged to Contain a String II [H]
// LeetCode count-substrings-that-can-be-rearranged-to-contain-a-string-ii

class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        unordered_map<char, int> dict;
        for(char c : word2) dict[c] += 1;
        int target = dict.size();
        unordered_map<char, int> windowDict;
        int count = 0;
        int n = word1.size();
        int left = n - 1, right = n - 1;
        long long ans = 0;
        while(left >= 0) {
            char leftC = word1[left];
            windowDict[leftC] += 1;
            if(windowDict[leftC] == dict[leftC]) count += 1;
            while(count >= target) {
                char rightC = word1[right];
                windowDict[rightC] -= 1;
                if(windowDict[rightC] == dict[rightC] - 1) count -= 1;
                right -= 1;
            }
            // cout << left << " " << right << endl;
            // cout << count << endl;
            ans += n - right - 1;
            left -= 1;
        }
        return ans;
    }
};
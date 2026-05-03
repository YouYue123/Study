#include <bits/stdc++.h>
using namespace std;

// 3306. Count of Substrings Containing Every Vowel and K Consonants II [M]
// LeetCode count-of-substrings-containing-every-vowel-and-k-consonants-ii

using ll = long long;
class Solution {
public:
    const unordered_set<char> vDict = { 'a', 'e', 'i', 'o', 'u' };
    ll f(string& s, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> dict;
        int cCount = 0;
        ll ans = 0;
        while(right < s.size()) {
            if(vDict.contains(s[right])) dict[s[right]] += 1;
            else cCount += 1;
            while(dict.size() == vDict.size() && cCount >= k) {
                if(vDict.contains(s[left])) {
                    dict[s[left]] -= 1;
                    if(dict[s[left]] == 0) dict.erase(s[left]);
                } else {
                    cCount -= 1;
                }
                left += 1;
            }
            ans += left;
            right += 1;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        return f(word, k) - f(word, k + 1);
    }
};
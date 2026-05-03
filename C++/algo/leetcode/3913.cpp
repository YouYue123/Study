#include <bits/stdc++.h>
using namespace std;

// 3913. Sort Vowels by Frequency [M]
// LeetCode sort-vowels-by-frequency

struct Item {
    int occ;
    int cnt;
    char c;
};
class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<Item> freq_dict;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        unordered_map<char, int> dict = {
            {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}
        };
        
        for(int i = 0; i < 5; i ++) {
            freq_dict.emplace_back(-1, 0, vowels[i]);
        }
        for(int i = 0; i < n; i ++) {
            char c = s[i];
            if(dict.contains(c)) {
                int idx = dict[c];
                if(freq_dict[idx].occ == -1) freq_dict[idx].occ = i;
                freq_dict[idx].cnt += 1;
            }
        }
        string ans = "";
        sort(freq_dict.begin(), freq_dict.end(), [&] (auto& a, auto& b) {
            if(a.cnt == b.cnt) return a.occ < b.occ;
            return a.cnt > b.cnt;
        });
        vector<char> sorted;
        for(auto& item: freq_dict) {
            for(int i = 0; i < item.cnt; i ++) {
                sorted.push_back(item.c);
            }
        }
        int p = 0;
        for(char c : s) {
            if(dict.contains(c)) {
                ans += sorted[p];
                p += 1;
            } else {
                ans += c;
            }
        }
        return ans;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 1170. Compare Strings by Frequency of the Smallest Character [M]
// LeetCode compare-strings-by-frequency-of-the-smallest-character

class Solution {
public:
    int f(string s) {
        pair<char, int> ans = {'~', 0};
        unordered_map<char, int> dict;
        // cout << s << endl;
        for(char c : s) {
            dict[c] += 1;
            if(c <= ans.first) {
                ans.first = c;
                ans.second = dict[c];
            }
        }
        // cout << ans.first << " " << ans.second << endl;
        return ans.second;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
        vector<int> freq;
        for(string& w: words) freq.push_back(f(w));
        sort(freq.begin(), freq.end());
        // for(auto i : freq) cout << i <<  " ";
        // cout << endl; 
        for(string& q : queries) {
            int targetFreq = f(q);
            // cout << "targetFreq: " << targetFreq << endl;
            int left = 0, right = freq.size();
            while(left < right) {
                int mid = left + (right - left) /2;
                if(freq[mid] > targetFreq) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            // cout << left << endl;
            ans.push_back(freq.size() - left);
        }
        return ans;
    }
};
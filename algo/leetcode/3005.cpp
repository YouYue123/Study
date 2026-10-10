#include <bits/stdc++.h>
using namespace std;

// 3005. Count Elements With Maximum Frequency [E]
// LeetCode count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int max_freq = 0;
        unordered_map<int, int> freq;
        for(int num : nums) {
            freq[num] += 1;
            max_freq = max(max_freq, freq[num]);
        }
        int ans = 0;
        for(auto& [num, cur_freq] : freq) {
            if(cur_freq == max_freq) ans += max_freq;
        }
        return ans;
    }
};
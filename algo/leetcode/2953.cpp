#include <bits/stdc++.h>
using namespace std;

// 2953. Count Complete Substrings [H]
// LeetCode count-complete-substrings

class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int ans = 0;
        for(int len = 1; len <= min((int)word.size() / k, 26); ++len) {
            int left = 0, right = 0;
            int exact = 0;
            int size = len * k;
            unordered_map<char, int> dict;
            while(right < word.size()) {
                // 检查相邻字符是否相差超过2（判断是否属于不同块）
                if(right > 0 && abs(word[right] - word[right - 1]) > 2) {
                    dict.clear();
                    exact = 0;
                    left = right; // 重置窗口
                }
                // 更新当前字符的计数
                char c = word[right];
                dict[c] += 1;
                 // 更新exact计数
                if(dict[c] == k) exact += 1; 
                else if(dict[c] == k + 1) exact -= 1;
               // 如果窗口大小超过目标，移动左指针
                if(right - left + 1 > size) {
                    char leftChar = word[left];
                    dict[leftChar] -= 1;
                    if(dict[leftChar] == k) exact += 1;
                    else if(dict[leftChar] == k - 1) exact -= 1;
                    left += 1;
                }
                 // 检查当前窗口是否满足条件
                if(right - left + 1 == size && exact == len) {
                    ans += 1;
                }
                
                right += 1;
            }
        }
        return ans;
    }
};
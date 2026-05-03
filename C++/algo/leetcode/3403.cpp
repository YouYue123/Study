#include <bits/stdc++.h>
using namespace std;

// 3403. Find the Lexicographically Largest String From the Box I [M]
// LeetCode find-the-lexicographically-largest-string-from-the-box-i

class Solution {
public:
    // 找到字符串 s 中字典序最大的子串
    string lastSubStr(string s) {
        int left = 0;  // 当前字典序最大子串的起始位置
        int right = 1; // 当前比较的子串的起始位置
        int n = s.size();
        
        while (right < n) {
            int k = 0; // 比较两个子串的公共前缀长度
            
            // 找到第一个不同的字符
            while (right + k < n && s[left + k] == s[right + k]) {
                k++;
            }
            
            // 如果以 right 开头的子串更大
            if (right + k < n && s[left + k] < s[right + k]) {
                int t = left; // 保存原来的 left
                left = right; // 更新 left 为 right
                // 更新 right，跳过已经比较过的部分
                right = max(right + 1, t + k + 1);
            } 
            // 否则以 left 开头的子串更大
            else {
                // 跳过已经比较过的部分
                right = right + k + 1;
            }
        }
        
        // 返回从 left 开始到末尾的子串
        return s.substr(left, n - left);
    }

    // 根据 numFriends 返回特定的子串
    string answerString(string word, int numFriends) {
        // 如果只有一个朋友，直接返回整个字符串
        if (numFriends == 1) {
            return word;
        }
        
        // 找到字典序最大的子串
        string last = lastSubStr(word);
        int n = word.size();
        int m = last.size();
        
        // 返回 last 的前缀，长度为 min(m, n - numFriends + 1)
        // 这是为了确保在分配给多个朋友时，尽可能保留字典序最大的部分
        return last.substr(0, min(m, n - numFriends + 1));
    }
};
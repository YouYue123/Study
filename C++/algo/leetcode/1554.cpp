#include <bits/stdc++.h>
using namespace std;

// 1554. Strings Differ by One Character [M]
// LeetCode strings-differ-by-one-character

class Solution {
public:
    bool differByOne(vector<string>& dict) {
        int n = dict.size();
        if (n <= 1) return false;
        int m = dict[0].size();
        vector<unsigned long long> hashes(n, 0);
        vector<unsigned long long> power(m, 1);

        // 预计算每个单词的全哈希和幂次
        for (int i = 0; i < m - 1; ++i) power[i + 1] = power[i] * 31;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hashes[i] = hashes[i] * 31 + (dict[i][j] - 'a' + 1);
            }
        }

        // 按列枚举：假设第 j 位不同
        for (int j = 0; j < m; ++j) {
            unordered_set<unsigned long long> seen;
            auto p = power[m - 1 - j];
            for (int i = 0; i < n; ++i) {
                // 计算移除第 j 位后的哈希值
                long long h = hashes[i] - (dict[i][j] - 'a' + 1) * p;
                if (seen.contains(h)) return true;
                seen.insert(h);
            }
        }
        return false;
    }
};
#include <bits/stdc++.h>
using namespace std;

// 2168. Unique Substrings With Equal Digit Frequency [M]
// LeetCode unique-substrings-with-equal-digit-frequency

class Solution {
public:
    int equalDigitFrequency(string s) {
        int n = s.size();
        // 使用 long long 组合两个哈希值，减少冲突概率
        unordered_set<long long> seenHashes;
        
        // 哈希参数
        const long long P = 131; // 质数底数
        const long long M = 1e9 + 7;
        const long long M2 = 1e9 + 9;

        for (int i = 0; i < n; ++i) {
            vector<int> counts(10, 0);
            int distinct_digits = 0;
            int max_freq = 0;
            long long hash1 = 0;
            long long hash2 = 0;

            for (int j = i; j < n; ++j) {
                int digit = s[j] - '0';
                
                // 1. 更新计数和状态
                if (counts[digit] == 0) distinct_digits++;
                counts[digit]++;
                max_freq = max(max_freq, counts[digit]);

                // 2. 滚动哈希计算 (基于当前数值)
                hash1 = (hash1 * P + (digit + 1)) % M;
                hash2 = (hash2 * P + (digit + 1)) % M2;
                long long combinedHash = (hash1 << 32) | hash2;

                // 3. 核心判定：总长度 == 种类数 * 最高频次
                int len = j - i + 1;
                if (len == max_freq * distinct_digits) {
                    seenHashes.insert(combinedHash);
                }
            }
        }
        
        return seenHashes.size();
    }
};
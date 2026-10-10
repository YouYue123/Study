#include <bits/stdc++.h>
using namespace std;

// 2524. Maximum Frequency Score of a Subarray [H]
// LeetCode maximum-frequency-score-of-a-subarray

constexpr int MOD = 1e9 + 7;

// 模加法
int modPlus(int a, int b, int mod = MOD) {
    return ((long long)(a) + b) % mod;
}

// 模减法
int modMinus(int a, int b, int mod = MOD) {
    return (((long long)(a) - b) + mod) % mod;
}

// 模乘法
int modMult(int a, int b, int mod = MOD) {
    return ((long long)(a) * b) % mod;
}

// 模幂运算（快速幂算法）
int modPow(int base, int exp, int mod = MOD) {
    long long result = 1;
    while (exp) {
        if (exp & 1) {
            result = modMult(result, base);
        }
        exp /= 2;
        base = modMult(base, base);
    }
    return result;
}

// 模逆元（费马小定理，仅适用于质数模）
int modInv(int a, int mod = MOD) {
    return modPow(a, mod - 2);
}

// 模除法
int modDiv(int a, int b, int mod = MOD) { 
    return modMult(a, modInv(b)); 
}

class Solution {
public:
        int maxFrequencyScore(std::vector<int>& nums, int k) {
        int left = 0, right = 0;  // 滑动窗口的左右指针
        int ans = INT_MIN;        // 存储最大分数
        unordered_map<int, int> freq;  // 记录当前窗口中各数字的频率
        int curVal = 0;           // 当前窗口的频率分数
    
        while(right < nums.size()) {
            // 处理右指针指向的数字
            int prevExp = freq[nums[right]];  // 该数字之前的频率
            freq[nums[right]] += 1;          // 频率增加
            
            // 更新当前分数：减去旧的贡献，加上新的贡献
            if(prevExp > 0) {
                int prevContribution = modPow(nums[right], prevExp);
                curVal = modMinus(curVal, prevContribution);
            } 
            int nextContribution = modPow(nums[right], freq[nums[right]]);
            curVal = modPlus(curVal, nextContribution);
            
            // 如果窗口大小超过k，需要移动左指针
            if(right - left + 1 > k) {
                int prevExp = freq[nums[left]];  // 左指针数字的频率
                int prevContribution = modPow(nums[left], prevExp);
                curVal = modMinus(curVal, prevContribution);
                
                freq[nums[left]] -= 1;  // 频率减少
                
                // 如果频率仍大于0，需要加上新的贡献
                if(freq[nums[left]] > 0) {
                    int nextContribution = modPow(nums[left], freq[nums[left]]);
                    curVal = modPlus(curVal, nextContribution); 
                }
                left += 1;  // 移动左指针
            }
            
            // 当窗口大小等于k时，更新最大分数
            if(right - left + 1 == k) {
                ans = max(ans, curVal);
            }
            
            right += 1;  // 移动右指针
        }
    
        return ans;
    }
};
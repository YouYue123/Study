// 2156. Find Substring With Given Hash Value [H]
// LeetCode find-substring-with-given-hash-value

class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        // 初始化当前哈希值、结果索引和power的k次方模modulo的值
        long long curHash = 0;
        long long resultIndex = 0;
        long long powerOfPrime = 1; // 用于存储power^k % modulo
        // 计算power^k % modulo，用于后续滑动窗口时的哈希值更新
        for(int i = 0; i < k; i++)  powerOfPrime = (powerOfPrime * power) % modulo;
        // 使用滑动窗口法从右向左遍历字符串
        int left = s.size() - 1;  // 窗口左边界
        int right = s.size() - 1; // 窗口右边界
        while(left >= 0) {
            // 计算当前字符的哈希贡献并更新当前哈希值
            // 哈希函数: (curHash * power + charValue) % modulo
            curHash = (curHash * power + (s[left] - 'a' + 1)) % modulo;
            // 如果窗口大小超过k，需要移除最右边字符的贡献
            if(right - left + 1 > k) {
                // 减去最右边字符的贡献 (charValue * power^k) % modulo
                // 加modulo是为了避免负数
                curHash = (curHash - (s[right] - 'a' + 1) * powerOfPrime % modulo + modulo) % modulo;
                right -= 1; // 移动右边界
            }
            // 当窗口大小等于k且哈希值匹配时，更新结果索引
            if(right - left + 1 == k && curHash == hashValue) resultIndex = left;
            left -= 1; // 移动左边界
        }
        // 返回找到的子串
        return s.substr(resultIndex, k);
    }
};
// 1763. Longest Nice Substring [E]
// LeetCode longest-nice-substring

class Solution {
public:
    // 辅助函数：获取字符的对应大小写形式
    char getOther(char c) {
        return isupper(c) ? tolower(c) : toupper(c);
    }
    
    string longestNiceSubstring(string s) {
        string ans = "";
        
        // 枚举可能的字符对数量k（1到26）
        for (int k = 1; k <= 26; k++) {
            int left = 0, right = 0;
            int count = 0; // 记录当前窗口中满足条件的字符对数量
            unordered_map<char, int> freq; // 记录窗口内字符频率
            
            while (right < s.size()) {
                // 扩展右边界，更新频率
                freq[s[right]] += 1;
                
                // 当字符首次出现时，检查其对应大小写形式
                if (freq[s[right]] == 1) {
                    auto other = getOther(s[right]);
                    if (freq.contains(other)) {
                        count += 1; // 如果对应形式存在，计数增加
                    }
                }
                
                // 当窗口内不同字符数量超过2*k时，收缩左边界
                while (freq.size() > 2 * k) {
                    freq[s[left]] -= 1;
                    if (freq[s[left]] == 0) {
                        auto other = getOther(s[left]);
                        if (freq.contains(other)) {
                            count -= 1; // 如果对应形式存在，计数减少
                        }
                        freq.erase(s[left]);
                    }
                    left += 1;
                }
                
                // 如果当前窗口满足条件且长度更长，更新结果
                if (count == k && right - left + 1 > ans.size()) {
                    ans = s.substr(left, right - left + 1);
                }
                
                right += 1;
            }
        }
        
        return ans;
    }
};
// 1156. Swap For Longest Repeated Character Substring [M]
// LeetCode swap-for-longest-repeated-character-substring

class Solution {
public:
    int maxRepOpt1(string text) {
        // 统计每个字符在字符串中出现的总次数
        unordered_map<char, int> count;
        for(char c : text) count[c] += 1;
        
        int ans = 0;    // 存储最终结果
        int left = 0;    // 滑动窗口的左边界
        
        while(left < text.size()) {
            int right = left;
            
            // step1: 找出当前连续的一段 [left, right)
            // 即找到从left开始连续的相同字符
            while(right < text.size() && text[right] == text[left]) {
                right += 1;
            }
            
            int curCount = right - left;  // 当前连续段的长度
            
            // step2: 如果这一段长度小于该字符出现的总数，并且前面或后面有空位，
            // 则可以使用交换操作将另一个该字符交换到相邻位置，使长度+1
            if(curCount < count[text[left]] && (right < text.size() || left > 0)) {
                ans = max(ans, curCount + 1);
            }
            
            // step3: 找到这一段后面与之相隔一个不同字符的另一段 [right + 1, k)
            // 即寻找是否有一段相同的字符可以通过交换中间的一个不同字符来连接两段
            int k = right + 1;
            while(k < text.size() && text[k] == text[left]) {
                k += 1;
            }
            
            // 计算可能的最大长度：
            // 1. 两段加上中间交换后的总长度 (k - left)
            // 2. 该字符在字符串中的总出现次数
            // 取两者较小值（因为最多只能有count[text[left]]个该字符）
            int maxCount = count[text[left]];
            ans = max(ans, min(k - left, maxCount));

            // 移动左指针到当前段的末尾，处理下一段
            left = right;
        }
        
        return ans;
    }
};
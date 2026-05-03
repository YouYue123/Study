// 686. Repeated String Match [M]
// LeetCode repeated-string-match

class Solution {
public:
   int repeatedStringMatch(string a, string b) {
        string res = "";
        int count = 0;
        
        // 1. 先叠加到长度刚好盖过 b
        while (res.size() < b.size()) {
            res += a;
            count++;
        }
        
        // 2. 检查当前是否包含 b
        if (res.find(b) != string::npos) return count;
        
        // 3. 再多加一个 a，处理跨界匹配（比如 a="abc", b="cabc"）
        res += a;
        if (res.find(b) != string::npos) return count + 1;
        
        return -1;
    }
};
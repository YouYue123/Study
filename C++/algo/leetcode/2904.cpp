// 2904. Shortest and Lexicographically Smallest Beautiful String [M]
// LeetCode shortest-and-lexicographically-smallest-beautiful-string

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int min_len = INT_MAX;
        string result = "";
        int left = 0, count = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            count += (s[right] == '1');
            
            while (count == k) {
                int current_len = right - left + 1;
                if (current_len < min_len) {
                    min_len = current_len;
                    result = s.substr(left, current_len);
                } else if (current_len == min_len) {
                    string candidate = s.substr(left, current_len);
                    if (candidate < result) {
                        result = candidate;
                    }
                }
                
                count -= (s[left++] == '1');
            }
        }
        
        return result;
    }
};
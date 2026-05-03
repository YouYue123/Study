// 3722. Lexicographically Smallest String After Reverse [M]
// LeetCode lexicographically-smallest-string-after-reverse

class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        string origin = s;
        for(int i = 0; i < s.size(); i ++) {
            reverse(s.begin(), s.begin() + i);
            if(ans > s) ans = s;
            s = origin;
        }
        for(int i = s.size() - 1; i >= 0; i --) {
            reverse(s.begin() + i, s.end());
            if(ans > s) ans = s;
            s = origin;
        }
        return ans;
    }
};
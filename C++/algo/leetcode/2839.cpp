// 2839. Check if Strings Can be Made Equal With Operations I [E]
// LeetCode check-if-strings-can-be-made-equal-with-operations-i

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        int n = s1.size();
        for(int i = 0; i < n - 2; i ++) {
            if(s1[i] != s2[i]) {
                if(s1[i + 2] != s2[i] || s1[i] != s2[i + 2]) {
                    return false;
                }
                swap(s1[i], s1[i + 2]);
            }
        }
        return s1 == s2;
    }
};
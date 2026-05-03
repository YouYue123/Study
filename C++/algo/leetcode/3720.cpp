// 3720. Lexicographically Smallest Permutation Greater Than Target [M]
// LeetCode lexicographically-smallest-permutation-greater-than-target

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnts(26 , 0);
        for(char c: s) cnts[c - 'a'] += 1;
        string ans = "";
        string temp = "";
        for(int i = 0; i < n; i ++) {
            char targetC = target[i];
            for(char nextC = targetC + 1; nextC <= 'z'; nextC += 1) {
                if(cnts[nextC - 'a'] <= 0) continue;
                string candidate = temp;
                candidate += nextC;
                cnts[nextC - 'a'] -= 1;
                for(int j = 0; j < 26; j ++) {
                    candidate += string(cnts[j], 'a' + j);
                }
                cnts[nextC - 'a'] += 1;
                if(ans.empty() || candidate < ans) ans = candidate;
                break;
            }
            if(cnts[targetC - 'a'] > 0) {
                cnts[targetC - 'a'] -= 1;
                temp += targetC;
            } else {
                break;
            }
        }
        return ans;
    }
};
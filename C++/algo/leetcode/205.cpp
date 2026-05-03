// 205. Isomorphic Strings [E]
// LeetCode isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> sDict;
        unordered_map<char, char> tDict;
        for(int i = 0; i < s.size(); i ++) {
            char sc = s[i];
            char tc = t[i];
            if(sDict.contains(sc) || tDict.contains(tc)) {
                if(!tDict.contains(tc) || !sDict.contains(sc)) return false;
                if(sDict[sc] != tc || tDict[tc] != sc) return false;
            } else {
                sDict[sc] = tc;
                tDict[tc] = sc;
            }
        }
        return true;
    }
};
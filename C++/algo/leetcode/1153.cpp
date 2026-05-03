// 1153. String Transforms Into Another String [H]
// LeetCode string-transforms-into-another-string

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        unordered_map<char, char> dict;
        unordered_set<char> uniqueInS2;
        for(int i = 0; i < str1.size(); i ++) {
            char c1 = str1[i];
            char c2 = str2[i];
            if(dict.contains(c1)) {
                if(dict[c1] != c2) return false;
            } else {
                dict[c1] = c2;
                uniqueInS2.insert(c2);
            }
        }
        cout << uniqueInS2.size() << endl;
        if(uniqueInS2.size() < 26) return true;
        else return false;
    }
};
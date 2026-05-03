// 3170. Lexicographically Minimum String After Removing Stars [M]
// LeetCode lexicographically-minimum-string-after-removing-stars

struct Node {
    int idx;
    char c;
    bool operator < (Node& other) {
        return idx < other.idx;
    }
    bool operator > (Node& other) {
        return idx > other.idx;
    }
};
class Solution {
public:
    string clearStars(string s) {
        unordered_map<int, stack<int>> dict;
        int totalSize = 0;
        for(int i = 0; i < s.size(); i ++) {
            char c = s[i];
            if(c == '*') {
                for(int j = 0; j < 26; j ++) {
                    if(!dict[j].empty()) {
                        s[dict[j].top()] = '*';
                        dict[j].pop();
                        break;
                    }
                }
            } else {
                dict[c - 'a'].push(i);
            }
        }
        string ans = "";
        for(char c : s) {
            if(c != '*') ans += c;
        }
        return ans;
    }
};
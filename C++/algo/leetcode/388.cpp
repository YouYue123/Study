#include <bits/stdc++.h>
using namespace std;

// 388. Longest Absolute File Path [M]
// LeetCode longest-absolute-file-path

class Solution {
public:
    int lengthLongestPath(string input) {
        deque<int> stack;
        int maxLen = 0;
        vector<string> parts = split(input, '\n');
        int ans = 0;
        for(const string& part : parts) {
            int level = part.rfind("\t") + 1;
            while(level < stack.size()) stack.pop_back();
            stack.push_back(part.size() - level);
            if(part.contains('.')) {
                int sum = 0;
                for(int len : stack) sum += len;
                sum += stack.size() - 1;
                ans = max(ans, sum);
            }
        }
        return ans;
    }

     vector<string> split(const string& s, char delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};
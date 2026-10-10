#include <bits/stdc++.h>
using namespace std;

// 1415. The k-th Lexicographical String of All Happy Strings of Length n [M]
// LeetCode the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

class Solution {
public:
    string getHappyString(int n, int k) {
        vector<char> dict = { 'a', 'b', 'c' };
        int cnt = 0;
        string ans = "";
        auto dfs = [&] (this auto&& dfs, string& cur) {
            if(cur.size() == n) {
                cnt += 1;
                if(cnt == k) ans = cur;
                return cnt < k;
            }
            for(int i = 0; i < dict.size(); i ++) {
                if(!cur.empty() && cur.back() == dict[i]) continue;
                cur.push_back(dict[i]);
                if(!dfs(cur)) return false;;
                cur.pop_back();
            }
            return true;
        };
        string tmp;
        dfs(tmp);
        return ans;
    }
};
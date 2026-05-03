#include <bits/stdc++.h>
using namespace std;

// 833. Find And Replace in String [M]
// LeetCode find-and-replace-in-string

class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        unordered_map < int , pair<int,string> > map;
        for (int i = 0 ; i < indices.size() ; i++ ){
            if ( sources[i] == s.substr(indices[i] , sources[i].size())){
                map[indices[i]] = {sources[i].size() , targets[i]};
            }
            
        }

        string ans = "";

        for ( int i = 0 ; i < s.size() ; ){
            
            if ( map.find(i) == map.end()){
                ans += s[i];
                i++;
            } else {
                ans += map[i].second;
                i += map[i].first;
            }
        }

        cout << ans << endl;

        return ans;

        
        
    }
};
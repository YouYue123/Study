#include <bits/stdc++.h>
using namespace std;

// 838. Push Dominoes [M]
// LeetCode push-dominoes

class Solution {
public:
    string pushDominoes(string dominoes) {
        stack<long> monoS;
        // dist to the closest L on right
        vector<long> ls(dominoes.size(), INT_MAX);
        // dist to the closest R on left
        vector<long> rs(dominoes.size(), INT_MAX);
        for(int i = 0; i < dominoes.size(); i ++) {
            char c = dominoes[i];
            if(c == '.')  monoS.push(i); 
            else if(c == 'L') {
                while(!monoS.empty()) {
                    // cout << monoS.top() << endl;
                    ls[monoS.top()] = i - monoS.top();
                    monoS.pop();
                }
            } else {
                while(!monoS.empty()) monoS.pop();
            }
        }
        while(!monoS.empty()) monoS.pop();
        for(int i = dominoes.size() - 1; i >= 0; i --) {
            char c = dominoes[i];
            if(c == '.') monoS.push(i);
            else if(c == 'R') {
                while(!monoS.empty()) {
                    rs[monoS.top()] = monoS.top() - i;
                    monoS.pop();
                }
            } else {
                while(!monoS.empty()) monoS.pop();
            }
        }
        string ans = dominoes;
        // for(int i : ls) cout << i << " ";
        // cout << endl;
        // for(int i : rs) cout << i << " ";
        // cout << endl;
        for(int i = 0; i < ans.size(); i ++) {
            if(ans[i] == '.') {
                if(ls[i] < rs[i]) ans[i] = 'L';
                else if(ls[i] > rs[i]) ans[i] = 'R';
            }
        }
        return ans;
    }
};
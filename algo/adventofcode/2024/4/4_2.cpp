#include <bits/stdc++.h>
using namespace std;

const string TARGET_WORD = "XMAS"; 
const int WORD_LENGTH = TARGET_WORD.length();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> g;
    string line;
    while(getline(cin, line)) g.push_back(line);
    int N = g.size(), M = g[0].size();
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
           char c = g[i][j];
           if(c == 'M' || c == 'S') {
              bool isValid = false;
              if(i + 1 < N && i + 2 < N && j + 1 < M && j + 2 < M) {
                if(c == 'M' && g[i + 1][j + 1] == 'A' && g[i + 2][j + 2] == 'S') isValid = true;
                if(c == 'S' && g[i + 1][j + 1] == 'A' && g[i + 2][j + 2] == 'M') isValid = true;
              }
              if(isValid) {
                int nc = g[i][j + 2];
                isValid = false;
                if(nc== 'M' || nc == 'S') {
                    if(nc == 'M' && g[i + 1][j + 1] == 'A' && g[i + 2][j] == 'S') isValid = true;
                    if(nc == 'S' && g[i + 1][j + 1] == 'A' && g[i + 2][j] == 'M') isValid = true;
                }
                ans += isValid;
              }
           }
        }
    }
    
    cout << ans << endl;
    return 0;
}
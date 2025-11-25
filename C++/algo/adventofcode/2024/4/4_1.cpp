#include <bits/stdc++.h>
using namespace std;

const string TARGET_WORD = "XMAS"; 
const int WORD_LENGTH = TARGET_WORD.length(); // 4

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> g;
    string line;
    while(getline(cin, line)) g.push_back(line);

    int N = g.size();
    int M = g[0].size();
    vector<pair<int, int>> dirs = {
        {0, 1}, {0, -1},  
        {1, 0}, {-1, 0},  
        {1, 1}, {-1, -1}, 
        {1, -1}, {-1, 1}  
    };
    
    int ans = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            
            if (g[i][j] != TARGET_WORD[0]) continue;
            
            for(const auto& d : dirs) {
                int dx = d.first;
                int dy = d.second;
                bool found = true;
                for(int k = 1; k < WORD_LENGTH; k++) {
                    int next_i = i + k * dx;
                    int next_j = j + k * dy;
                    if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= M) {
                        found = false;
                        break;
                    }
                    if (g[next_i][next_j] != TARGET_WORD[k]) {
                        found = false;
                        break;
                    }
                }             
                if (found) ans++;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
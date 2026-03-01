#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;
using pii = pair<int, int>;
int MOD = 1e9 + 7;
struct PairHash {
    int operator()(const pii& v) const {
        
        return hash<int>{}(v.first) % MOD + (hash<int>{}(v.second));
    }
};
// 模拟电子表格数据
// A1 -> B2, B2 -> C1, C1 -> A1 (这是一个环)
vector<vector<string>> spreadsheet = {
    {"B1", "C1", "A2"},  // Row 1 (Index 0): A1, B1, C1
    {"B2",  "C2", "A3"}, // Row 2 (Index 1): A2, B2, C2
    {"B3", "C3",  "A1"}   // Row 3 (Index 2): A3, B3, C3
};

// All 0-indexed
pii parseAddr(string& cell) {
    string colStr = "";
    string rowStr = "";
    for(char c : cell) {
        if(isalpha(c)) colStr += c;
        else if(isdigit(c)) rowStr += c;
    }
    int col = 0;
    for(char c : colStr) {
        col = col * 26 + (c - 'A' + 1);
    }
    // 关键：col 也要减 1，这样 A 对应 0，B 对应 1
    return { stoi(rowStr) - 1, col - 1 }; 
}

// All 1-indexed
string toAddr(pii& node) {
    string colStr = "";
    int row = node.first;
    int col = node.second;
    while (col >= 0) {
        colStr = (char)('A' + (col % 26)) + colStr;
        col = (col / 26) - 1; 
    }
    return colStr + to_string(row + 1);
}

void solve1 () {
    int m = spreadsheet.size(), n = spreadsheet[0].size();
    unordered_map<pii, pii, PairHash> g;
    vector<pii> cyclePath;
    unordered_map<pii, pii, PairHash> parent;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            auto& s = spreadsheet[i][j];
            pair<int, int> cur = { i, j };
            auto nxt = parseAddr(s);
            if(nxt.first >= 0 && nxt.second >= 0) {
                g[cur] = nxt;
            }
        }
    }
    
    vector visited(m, vector(n, 0));
    auto dfs = [&] (auto dfs, pii node) {
        if(visited[node.first][node.second] == 1) {
            cyclePath.push_back(node);
            pii temp = parent[node];
            while(!(temp.first == node.first && temp.second == node.second)) {
                cyclePath.push_back(temp);
                temp = parent[temp];
            }
            reverse(cyclePath.begin(), cyclePath.end());
            return true;
        }
        if(visited[node.first][node.second] == 2) return false;
        visited[node.first][node.second] = 1;
        if(g.contains(node)) {
            parent[g[node]] = node;
            if(dfs(dfs, g[node])) return true;
        }
        visited[node.first][node.second] = 2;
        return false;
    };
    bool hasCycle = false;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(dfs(dfs, {i, j})) {
                hasCycle = true;
                break;
            }
        }
        if(hasCycle) break;
    }
    if(!hasCycle) cout << "No Cycle Found" << endl;
    else {
        cout << "Cycle Detected" << endl;
        for(auto& p : cyclePath) {
            cout << toAddr(p)  << endl;
        }
    }
}

void solve2 () {
    int m = spreadsheet.size(), n = spreadsheet[0].size();
    
    unordered_map<pii, pii, PairHash> g;
    unordered_map<pii, int, PairHash> degree;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            auto& s = spreadsheet[i][j];
            pair<int, int> cur = { i, j };
            auto nxt = parseAddr(s);
            if(nxt.first >= 0 && nxt.second >= 0) {
                g[cur] = nxt;
                degree[nxt] += 1;
            }
        }
    }
    queue<pii> q;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            if(degree[{i, j}] == 0) {
                q.emplace(i, j);
            }
        }
    }
    int cnt = 0;
    while(!q.empty()) {
        pii cur = q.front();
        q.pop();
        cnt += 1;
        if(g.contains(cur)) {
            pii nxt = g[cur];
            degree[nxt] -= 1;
            if(degree[nxt] == 0) q.push(nxt);
        }
    }
    if(cnt == m * n) cout << "No Cycle Found" << endl;
    else cout << "Cycle Detected" << endl;
}


int main() {
    solve1();
    solve2();
    return 0;
}
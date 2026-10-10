#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// void solve()
// {
//     vector<>
// }

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    vector<int> a;
    vector<int> b;
    int ans = 0;
    string line;
    int i = 0;
    while(getline(cin, line)) {
        i += 1;
        stringstream ss(line);
        int num;
        vector<int> row;
        while(ss >> num) row.push_back(num);
        bool increase = false;
        if(row.front() == row.back()) continue;
        if(row.front() < row.back()) increase = true;
        bool isSafe = true;
        for(int i = 1; i < row.size(); i ++) {
            if(increase) {
                if(row[i] - row[i - 1] > 3 || row[i] - row[i - 1] < 1) {
                    isSafe = false;
                    break;
                }
            }
            if(!increase) {
                if(row[i - 1] - row[i] > 3 || row[i - 1] - row[i] < 1) {
                    isSafe = false;
                    break;
                }
            }
        }
        ans += isSafe;
    }
    cout << ans << endl;
}
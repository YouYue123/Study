#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string line;
    ull ans = 0;
    while(getline(cin, line)) {
        int n = line.size();
        int curMax = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = i + 1; j < n; j ++) {
                string temp = "";
                temp.push_back(line[i]);
                temp.push_back(line[j]);
                curMax= max(curMax, stoi(temp));
            }
        }
        ans += curMax;
    }
    cout << "ans:" << ans << endl;
}
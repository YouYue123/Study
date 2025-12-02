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
       stringstream ss(line);
       // "11-22,95-115
       while(getline(ss, line, ',')) {
            stringstream ss2(line);
            string start, end;
            while(getline(ss2, start, '-')) {
                getline(ss2, end, '-');
                ull start_num = stoull(start);
                ull end_num = stoull(end);
                // cout << "start: " << start << " end: " << end << endl;
                
            }
       }
    }
    cout << ans << endl;
}
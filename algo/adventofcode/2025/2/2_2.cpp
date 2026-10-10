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
                for(ull num = start_num; num <= end_num; num++) {
                    string num_str = to_string(num);
                    bool find = false;
                    for(int t = 1; t < num_str.size(); t++) {
                        if(num_str.size() % t != 0) continue;
                        bool valid = false;
                        string part = num_str.substr(0, t);
                        // cout << "part: " << part << endl;
                        for(int k = t; k < num_str.size(); k += t) {
                            // cout << "num_str.substr(k, t): " << num_str.substr(k, t) << endl;
                            if(num_str.substr(k, t) != part) {
                                valid = true;
                                break;
                            }
                        }
                        if(valid == false) {
                            // cout << num_str << " could be divided by " << t << " times" << endl;
                            // cout << "part: " << part << endl;
                            find = true;
                            break;
                        }
                    }
                    if(find) {
                        cout << "invalid: " << num_str << endl;
                        ans += num;
                    }
                }
            }
       }
    }
    cout << ans << endl;
}
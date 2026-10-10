#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s(
        (istreambuf_iterator<char>(cin)),
         istreambuf_iterator<char>()
    );
    const regex pattern(
        R"((mul\(([-+]?\d+),([-+]?\d+)\))|(do\(\))|(don\'t\(\)))"
    );
    sregex_iterator begin(s.begin(), s.end(), pattern);
    sregex_iterator end;
    ll ans = 0;
    bool enabled = true; 
    for (sregex_iterator i = begin; i != end; ++i) {
        smatch match = *i;
        string full_match = match[0].str();
        if (match[4].matched) enabled = true;
        else if (match[5].matched) enabled = false;
        else if (match[1].matched) { 
            if (enabled) {
                int num1 = stoi(match[2].str());
                int num2 = stoi(match[3].str());
                ll result = (ll)num1 * num2;
                ans += result;
            }
        }
    }
    cout << ans << endl;
}
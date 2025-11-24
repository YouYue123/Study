#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    s.assign(
        (istreambuf_iterator<char>(cin)),
         istreambuf_iterator<char>()
    );
    using RegexIterator = sregex_iterator;
    const regex pattern(R"(mul\(([-+]?\d*\.?\d+),([-+]?\d*\.?\d+)\))");
    RegexIterator begin(s.begin(), s.end(), pattern);
    RegexIterator end;
    long long ans = 0;
    for(RegexIterator i = begin; i != end; i ++) {
        smatch match = *i;
        int idx = match.position();
        string fullMatch = match[0].str();
        string num1 = match[1].str();
        string num2 = match[2].str();
        cout << num1 << " " << num2 << endl;
        ans += stoi(num1) * stoi(num2);
    }
    cout << ans << endl;
}
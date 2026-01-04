#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const std::string WHITESPACE = " \n\r\t\f\v";

std::string ltrim(const std::string& s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

// Trim from the end (right)
std::string rtrim(const std::string& s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

// Trim from both ends
std::string trim(const std::string& s) {
    return rtrim(ltrim(s));
}
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string s;
    getline(cin, s);
    s = s.substr(1, s.size() - 2);
    // cout << s << endl;
    stringstream ss(s);
    unordered_set<string> set;
    while(ss.good()) {
        string c;
        getline(ss, c, ',');
        c = trim(c);
        if(c.empty()) continue;
        set.insert(c);
    }
    cout << set.size() << endl;
}
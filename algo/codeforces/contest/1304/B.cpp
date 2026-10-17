#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    string s;
    string rev_s;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<Item> items;
    auto is_palindrome = [&] (string& s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if(s[left] != s[right]) return false;
            left += 1;
            right -= 1;
        }
        return true;
    };
    
    for(int i = 0; i < n; i ++) {
        string s;
        cin >> s;
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        items.emplace_back(s, rev_s);
    }
    string front = "";
    vector choose(n, false);
    for(int i = 0; i < n; i ++) {
        // cout << i << endl;
        if(choose[i]) continue;
        for(int j = i + 1; j < n; j ++) {
            if(choose[j]) continue;
            // cout << items[i].s << " " << items[j].s << endl;
            if(items[i].s == items[j].rev_s) {
                front += items[i].s;
                choose[i] = true;
                choose[j] = true;
                continue;
            }
        }
    }
    string mid = "";
    for(int i = 0; i < n; i ++) {
        if(choose[i]) continue;
        if(is_palindrome(items[i].s)) {
            mid = items[i].s;
            break;
        }
    }
    string back = front;
    reverse(back.begin(), back.end());
    string ans = front + mid + back;
    assert(is_palindrome(ans) == true);
    cout << ans.size() << endl;
    cout << ans << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}
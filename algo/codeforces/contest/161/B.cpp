#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Item {
    int idx;
    double price;
};
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<Item> stools;
    vector<Item> pencils;
    double total = 0.0;
    for(int i = 0; i < n; i ++) {
        double c, t;
        cin >> c >> t;
        if(t == 1) stools.emplace_back(i + 1, c); 
        else pencils.emplace_back(i + 1, c);
    }
    sort(stools.begin(), stools.end(), [&] (auto& a, auto& b) { return a.price > b.price; });
    sort(pencils.begin(), pencils.end(), [&] (auto& a, auto& b) { return a.price < b.price; } );
    int stool_cnt = stools.size(), pencil_cnt = pencils.size();
    vector<vector<ll>> ans;
    double total_cost = 0.0;
    int p1 = 0, p2 = 0;
    while(p1 < min(k - 1, stool_cnt)) {
        ans.push_back({ stools[p1].idx });
        total_cost += 0.5 * stools[p1].price;
        p1 += 1;
    }
    if(p1 < stools.size()) {
        ans.push_back({});
        double min_price = INF;
        for(int i = p1; i < stool_cnt; i ++) {
            ans.back().push_back(stools[i].idx);
            total_cost += stools[i].price;
            min_price = min(min_price, stools[i].price);
        }
        for(int i = 0; i < pencil_cnt; i ++) {
            ans.back().push_back(pencils[i].idx);
            total_cost += pencils[i].price;
            min_price = min(min_price, pencils[i].price);
        };
        total_cost -= 0.5 * min_price;
    } else {
        while(p1 < k - 1) {
            ans.push_back({});
            ans.back().push_back(pencils[p2].idx);
            total_cost += pencils[p2].price;
            p1 += 1;
            p2 += 1;
        }
        ans.push_back({});
        while(p2 < pencil_cnt) {
            ans.back().push_back(pencils[p2].idx);
            total_cost += pencils[p2].price;
            p2 += 1;
        }
    }
    cout << std::fixed << setprecision(1) << total_cost << endl;
    for(auto& cart : ans) {
        cout << cart.size() << " ";
        for(auto& item : cart) {
            cout << item << " "; 
        }
        cout << endl;
    }
    
}
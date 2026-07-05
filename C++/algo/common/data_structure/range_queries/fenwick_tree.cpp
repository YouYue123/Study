#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://oi-wiki.org/ds/fenwick/
// Binary Indexed Tree (also known as Fenwick Tree) data structure
struct BIT {
    vector<int> tree;
    // assume a is 0 indxed 
    BIT(vector<ll>& a){
        tree.assign(a.size() + 1, 0);
        for(int i = 0; i < a.size(); i ++) {
            update(i + 1, a[i]);
        }
    }
    int lowbit(int i) {
        return i & (-i);
    }
    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += lowbit(idx);
        }
    }
    int query(int idx) {
        int ans = 0;
        while (idx > 0) {
            ans += tree[idx];
            idx -= lowbit(idx); 
        }
        return ans;
    }
};

// CSES 1144 Salary Queries: coordinate-compress values, BIT stores salary frequencies.
// ! k x — set employee k's salary to x; ? a b — count salaries in [a, b].
// struct Query {
//     char op;
//     ll val_1;
//     ll val_2;
// };
// void solve() {
//     int n, q;
//     cin >> n >> q;
//     vector<ll> p(n);
//     for(int i = 0; i < n; i ++) cin >> p[i];

//     vector<Query> queries(q);
//     vector<ll> all_vals(p.begin(), p.end());

//     for (int i = 0; i < q; i++) {
//         cin >> queries[i].op >> queries[i].val_1 >> queries[i].val_2;
//         if(queries[i].op == '!') all_vals.push_back(queries[i].val_2); 
//         else {
//             all_vals.push_back(queries[i].val_1); 
//             all_vals.push_back(queries[i].val_2); 
//         }
//     }

//     sort(all_vals.begin(), all_vals.end());
//     all_vals.erase(unique(all_vals.begin(), all_vals.end()), all_vals.end());

//     auto get_idx = [&](ll v) -> int {
//         return (int)(lower_bound(all_vals.begin(), all_vals.end(), v) - all_vals.begin()) + 1;
//     };

//     int m = all_vals.size();
//     BIT bit(m);

//     for (int i = 0; i < n; i++) {
//         bit.update(get_idx(p[i]), 1);
//     }

//     for (int i = 0; i < q; i++) {
//         if (queries[i].op == '!') {
//             ll k = queries[i].val_1, x = queries[i].val_2;
//             ll prevSalary = p[k - 1];
//             bit.update(get_idx(prevSalary), -1);
//             bit.update(get_idx(x), 1);
//             p[k - 1] = x;
//         } else {
//             ll a = queries[i].val_1, b = queries[i].val_2;
//             int lo = get_idx(a);
//             int hi = get_idx(b);
//             cout << bit.query(hi) - bit.query(lo - 1) << "\n";
//         }
//     }
// }

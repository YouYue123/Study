// 3525. Find X Value of Array II [H]
// LeetCode find-x-value-of-array-ii

#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, n) for (lli i = (a); i < (n); ++i)
#define loopD(i, a, n) for (lli i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define sz(a) ((int)a.size())
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
// #define endl '\n'
#define fastio std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define pb push_back
#define pp pop_back()
#define fi first
#define si second
#define v(a) vector<int>(a)
#define vv(a) vector<vector<int>>(a)
#define pansent(c, x) ((c).find(x) != (c).end())
#define set_bits __builtin_popcountll
#define MOD 1000000007
// #define int long long

typedef long long lli;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pll;
typedef pair<int, int> pii;
typedef unordered_map<int, int> umpi;
typedef map<int, int> mpi;
typedef vector<pii> vp;
typedef vector<lli> vll;
typedef vector<vll> vvll;

static const int MAXK = 5;

struct node {
    int prod;
    int cnt[MAXK];
    node(int k = 0) {
        prod = 1 % max(1, k);
        memset(cnt, 0, sizeof(cnt));
    }
};

class Solution {
    int n, k, sizeST;
    vector<node> seg;
    node mergeNode(const node &L, const node &R) const {
        node res(k);
        res.prod = int((1LL * L.prod * R.prod) % k);
        for (int r = 0; r < k; ++r) res.cnt[r] = L.cnt[r];
        for (int r2 = 0; r2 < k; ++r2) {
            int c = R.cnt[r2];
            if (c) {
                int r = int((1LL * L.prod * r2) % k);
                res.cnt[r] += c;
            }
        }
        return res;
    }

    
    void build(const vector<int> &a) {
        sizeST = 1;
        while (sizeST < n) sizeST <<= 1;
        seg.assign(2 * sizeST, node(k));
        for (int i = 0; i < n; ++i) {
            int v = a[i] % k;
            node &nd = seg[sizeST + i];
            nd = node(k);
            nd.prod = v;
            nd.cnt[v] = 1;
        }
        for (int p = sizeST - 1; p > 0; --p) {
            seg[p] = mergeNode(seg[2*p], seg[2*p + 1]);
        }
    }

    
    void updateSeg(int idx, int vmod) {
        int p = sizeST + idx;
        seg[p] = node(k);
        seg[p].prod = vmod;
        seg[p].cnt[vmod] = 1;
        for (p >>= 1; p > 0; p >>= 1) {
            seg[p] = mergeNode(seg[2*p], seg[2*p + 1]);
        }
    }

    node querySeg(int l, int r) const {
        node resL(k), resR(k);
        for (l += sizeST, r += sizeST; l <= r; l >>= 1, r >>= 1) {
            if (l & 1)  resL = mergeNode(resL, seg[l++]);
            if (!(r & 1)) resR = mergeNode(seg[r--], resR);
        }
        return mergeNode(resL, resR);
    }

public:
    vector<int> resultArray(vector<int>& nums, int kk, vector<vector<int>>& queries) {
        n = sz(nums);
        k = kk;
        build(nums);
        int q = sz(queries);
        vector<int> ans(q);
        for (int i = 0; i < q; ++i) {
            updateSeg(queries[i][0], queries[i][1] % k);
            node nd = querySeg(queries[i][2], n - 1);
            ans[i] = nd.cnt[queries[i][3]];
        }
        return ans;
    }
};
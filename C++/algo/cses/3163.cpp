#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;

struct SegTreePersist {
    int n;
    vector<int> left_children; // 存储每个节点的左儿子节点编号（下标）
    vector<int> right_children; // 存储每个节点的右儿子节点编号（下标）
    vector<ll> sum; // 存储每个节点管辖区间内的元素个数（权值和）
    vector<int> root; // 存储每个版本根节点的编号。root[i] 表示第 i 个版本的根
    int cur_version = 0;
    SegTreePersist(int n): n(n) {
        // 压入 0 号 dummy 节点
        left_children.push_back(0);
        right_children.push_back(0);
        sum.push_back(0);
        // 建立空树，作为版本 0
        root.push_back(_build(0, n - 1));
    }

    int _build(int left, int right) {
        if(left == right) {
            return _new_node(0, 0, 0);
        }
        int mid = left + (right - left) / 2;
        int L = _build(left, mid);
        int R = _build(mid + 1, right);
        return _new_node(L, R, 0);
    }

    int _new_node(int left_child, int right_child, ll val) {
        left_children.push_back(left_child);
        right_children.push_back(right_child);
        sum.push_back(val);
        // 返回新节点的编号（即 vector 的最后一位下标）
        return sum.size() - 1;
    }
    
    // 从版本 ver 复制并在 pos 位置 +1，返回新版本号。
    void new_version(int pos) {
        int new_root = _insert(root[cur_version], 0, n - 1, pos);
        root.push_back(new_root);
        cur_version = root.size() - 1;
    }
    int _insert(int prev, int left, int right, int pos) {
        if(left == right) return _new_node(0, 0, sum[prev] + 1); // 叶子节点：新值 = 旧值 + 1
        int mid = left + (right - left) / 2;
        if(pos <= mid) {
            // 如果修改点在左子树，递归去建左边的新节点
            int new_L = _insert(left_children[prev], left, mid, pos);
            // 右子树没有受影响，直接复用前一个版本的右儿子 rc[prev]！
            return _new_node(new_L, right_children[prev], sum[new_L] + sum[right_children[prev]]);
        } else {
            // 同理，如果修改点在右子树，左子树直接复用 lc[prev]
            int new_R = _insert(right_children[prev], mid + 1, right, pos);
            return _new_node(left_children[prev], new_R, sum[left_children[prev]] + sum[new_R]);
        }
    }

    ll query(int ver_a, int ver_b, int q_left, int q_right) {
        return _query(root[ver_a], root[ver_b], 0, n - 1, q_left, q_right);
    }
    ll _query(int node_a, int node_b, int left, int right, int q_left, int q_right) {
        if(q_right < left || q_left > right) return 0;
        // 当完全覆盖当前区间时，利用前缀和思想相减：
        if(q_left <= left && right <= q_right) return sum[node_b] - sum[node_a];
        int mid = left + (right - left) / 2;
        return _query(left_children[node_a], left_children[node_b], left, mid, q_left, q_right) +
               _query(right_children[node_a], right_children[node_b], mid + 1, right, q_left, q_right);
    }
};
void solve() {
    int n, q;
    cin >> n >> q;
    vector x(n, 0LL);
    vector vals(n, 0LL);
    for(int i = 0; i < n; i ++) {
        cin >> x[i];
        vals[i] = x[i];
    }
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();
    auto seg_tree = SegTreePersist(m);
    
    auto get_lower_idx = [&] (ll val) {
        return lower_bound(vals.begin(), vals.end(), val) - vals.begin(); 
    };

    for(int i = 0; i < n; i ++) {
        seg_tree.new_version(get_lower_idx(x[i]));
    }

    for(int i = 0; i < q; i ++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int c_idx = get_lower_idx(c);
        int d_idx = upper_bound(vals.begin(), vals.end(), d) - vals.begin();
        cout << seg_tree.query(a - 1, b, c_idx, d_idx - 1) << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
#include <bits/stdc++.h>
using namespace std;

/**
 * https://oi-wiki.org/ds/seg/#%E7%BA%BF%E6%AE%B5%E6%A0%91%E7%9A%84%E5%8C%BA%E9%97%B4%E4%BF%AE%E6%94%B9%E4%B8%8E%E6%87%92%E6%83%B0%E6%A0%87%E8%AE%B0
 * 延迟标记线段树（区间修改、区间查询）
 * 支持的操作：
 * - 区间更新
 * - 区间查询
 * - 线段树二分
 * 
 * 使用示例：
 *   vector<int> a = {1, 2, 3, 4, 5};
 *   LazySegmentTree seg(a);
 *   seg.update(1, 0, 2, 10);  // 将区间[0,2]每个元素加10
 *   int sum = seg.query(1, 0, 2);  // 查询区间[0,2]的和
 */
struct LazySegmentTree {
    struct Node {
        int l, r;
        int sum;   // 区间信息（可以是sum, max, min等）
        int todo;  // 延迟标记
    };
    
    vector<Node> tree;
    int n;
    const int TODO_INIT = 0;  // 延迟标记的初始值
    
    // 合并两个节点的信息
    int mergeInfo(int a, int b) {
        return a + b;  // 默认是求和，可以改为max, min等
    }
    
    // 合并两个延迟标记
    int mergeTodo(int a, int b) {
        return a + b;  // 默认是区间加，可以改为其他操作
    }
    
    // 应用延迟标记到节点
    void apply(int o, int f) {
        Node& cur = tree[o];
        // 更新f对整个区间的影响（本例为区间加）
        cur.sum += f * (cur.r - cur.l + 1);
        cur.todo = mergeTodo(f, cur.todo);
    }
    
    // 维护节点信息
    void maintain(int o) {
        tree[o].sum = mergeInfo(tree[o<<1].sum, tree[o<<1|1].sum);
    }
    
    // 下传延迟标记
    void spread(int o) {
        int f = tree[o].todo;
        if (f == TODO_INIT) {
            return;
        }
        apply(o<<1, f);
        apply(o<<1|1, f);
        tree[o].todo = TODO_INIT;
    }
    
    // 构建线段树
    void build(const vector<int>& a, int o, int l, int r) {
        tree[o].l = l;
        tree[o].r = r;
        tree[o].todo = TODO_INIT;
        if (l == r) {
            tree[o].sum = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, o<<1, l, m);
        build(a, o<<1|1, m+1, r);
        maintain(o);
    }
    
    // 区间更新
    // o: 节点编号（从1开始）
    // l, r: 更新区间（0<=l<=r<=n-1）
    // f: 更新值（例如区间加的值）
    void update(int o, int l, int r, int f) {
        if (l <= tree[o].l && tree[o].r <= r) {
            apply(o, f);
            return;
        }
        spread(o);
        int m = (tree[o].l + tree[o].r) >> 1;
        if (l <= m) {
            update(o<<1, l, r, f);
        }
        if (m < r) {
            update(o<<1|1, l, r, f);
        }
        maintain(o);
    }
    
    // 区间查询
    int query(int o, int l, int r) {
        if (l <= tree[o].l && tree[o].r <= r) {
            return tree[o].sum;
        }
        spread(o);
        int m = (tree[o].l + tree[o].r) >> 1;
        if (r <= m) {
            return query(o<<1, l, r);
        }
        if (m < l) {
            return query(o<<1|1, l, r);
        }
        int lRes = query(o<<1, l, r);
        int rRes = query(o<<1|1, l, r);
        return mergeInfo(lRes, rRes);
    }
    
    // 查询整个区间
    int queryAll() {
        return tree[1].sum;
    }
    
    // 线段树二分：返回[l,r]内第一个满足f的下标
    int findFirst(int o, int l, int r, function<bool(int)> f) {
        if (tree[o].l > r || tree[o].r < l || !f(tree[o].sum)) {
            return -1;
        }
        if (tree[o].l == tree[o].r) {
            return tree[o].l;
        }
        spread(o);
        int idx = findFirst(o<<1, l, r, f);
        if (idx < 0) {
            idx = findFirst(o<<1|1, l, r, f);
        }
        return idx;
    }
    
    // 线段树二分：返回[l,r]内最后一个满足f的下标
    int findLast(int o, int l, int r, function<bool(int)> f) {
        if (tree[o].l > r || tree[o].r < l || !f(tree[o].sum)) {
            return -1;
        }
        if (tree[o].l == tree[o].r) {
            return tree[o].l;
        }
        spread(o);
        int idx = findLast(o<<1|1, l, r, f);
        if (idx < 0) {
            idx = findLast(o<<1, l, r, f);
        }
        return idx;
    }
    
    // 构造函数
    LazySegmentTree(const vector<int>& a) {
        n = a.size();
        if (n == 0) {
            throw runtime_error("array cannot be empty");
        }
        int size = 2 << (32 - __builtin_clz(n - 1));
        tree.resize(size);
        build(a, 1, 0, n - 1);
    }
};
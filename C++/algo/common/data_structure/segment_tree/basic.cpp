#include <bits/stdc++.h>
using namespace std;

// 线段树讲解 by 灵茶山艾府
// 可视化 https://visualgo.net/zh/segmenttree
// 推荐阅读《算法竞赛进阶指南》0x43 和 0x48 节
// https://oi-wiki.org/ds/seg/
// https://cp-algorithms.com/data_structures/segment_tree.html

/**
 * 基础线段树（单点修改、区间查询）
 * 支持的操作：
 * - 单点更新
 * - 区间查询
 * - 线段树二分（findFirst/findLast）
 * 
 * 使用示例：
 *   vector<int> a = {1, 2, 3, 4, 5};
 *   SegmentTree seg(a);
 *   seg.update(1, 0, 10);  // 将位置0的值更新为10
 *   int maxVal = seg.query(1, 0, 2);  // 查询区间[0,2]的最大值
 */
struct SegmentTree {
    struct Node {
        int l, r;
        int val;  // 根据需求修改：可以是max, min, sum, gcd等
    };
    
    vector<Node> tree;
    int n;
    
    // 合并两个节点的信息
    // 默认是最大值，可以根据需求修改为min, sum, gcd等
    int mergeInfo(int a, int b) {
        return max(a, b);
    }
    
    // 单点更新：设置节点值
    void set(int o, int val) {
        tree[o].val = mergeInfo(tree[o].val, val);
    }
    
    // 维护节点信息（向上更新）
    void maintain(int o) {
        tree[o].val = mergeInfo(tree[o<<1].val, tree[o<<1|1].val);
    }
    
    // 构建线段树
    // o: 节点编号（从1开始）
    // l, r: 区间左右端点（从0开始）
    void build(const vector<int>& a, int o, int l, int r) {
        tree[o].l = l;
        tree[o].r = r;
        if (l == r) {
            tree[o].val = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(a, o<<1, l, m);
        build(a, o<<1|1, m+1, r);
        maintain(o);
    }
    
    // 单点更新
    // o: 节点编号（从1开始）
    // i: 要更新的位置（0<=i<=n-1）
    // val: 新值
    void update(int o, int i, int val) {
        if (tree[o].l == tree[o].r) {
            set(o, val);
            return;
        }
        int m = (tree[o].l + tree[o].r) >> 1;
        if (i <= m) {
            update(o<<1, i, val);
        } else {
            update(o<<1|1, i, val);
        }
        maintain(o);
    }
    
    // 区间查询
    // o: 节点编号（从1开始）
    // l, r: 查询区间（0<=l<=r<=n-1）
    int query(int o, int l, int r) {
        if (l <= tree[o].l && tree[o].r <= r) {
            return tree[o].val;
        }
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
        return tree[1].val;
    }
    
    // 线段树二分：返回[l,r]内第一个满足f的下标，如果不存在返回-1
    // 例如查询[l,r]内第一个大于等于target的元素下标
    //     seg.findFirst(1, l, r, [target](int nodeMax) { return nodeMax >= target; });
    int findFirst(int o, int l, int r, function<bool(int)> f) {
        if (tree[o].l > r || tree[o].r < l || !f(tree[o].val)) {
            return -1;
        }
        if (tree[o].l == tree[o].r) {
            return tree[o].l;
        }
        int idx = findFirst(o<<1, l, r, f);
        if (idx < 0) {
            idx = findFirst(o<<1|1, l, r, f);
        }
        return idx;
    }
    
    // 线段树二分：返回[l,r]内最后一个满足f的下标，如果不存在返回-1
    int findLast(int o, int l, int r, function<bool(int)> f) {
        if (tree[o].l > r || tree[o].r < l || !f(tree[o].val)) {
            return -1;
        }
        if (tree[o].l == tree[o].r) {
            return tree[o].l;
        }
        int idx = findLast(o<<1|1, l, r, f);
        if (idx < 0) {
            idx = findLast(o<<1, l, r, f);
        }
        return idx;
    }
    
    // 构造函数
    // a: 初始数组（下标从0开始）
    SegmentTree(const vector<int>& a) {
        n = a.size();
        if (n == 0) {
            throw runtime_error("array cannot be empty");
        }
        // 计算线段树大小：2 << ceil(log2(n))
        int size = 2 << (32 - __builtin_clz(n - 1));
        tree.resize(size);
        build(a, 1, 0, n - 1);
    }
};



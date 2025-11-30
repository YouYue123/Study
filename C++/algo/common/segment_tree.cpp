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

/**
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

/**
 * 动态开点线段树（隐式线段树）
 * 适用于值域很大但实际使用的点很少的情况
 * 不需要离散化，节省空间
 * 
 * 使用示例：
 *   DynamicSegmentTree seg(0, 1e9);  // 值域[0, 1e9]
 *   seg.update(seg.root, 1000000, 10);  // 在位置1000000更新为10
 *   int val = seg.query(seg.root, 500000, 2000000);  // 查询区间[500000, 2000000]
 */
struct DynamicSegmentTree {
    struct Node {
        Node* lo = nullptr;
        Node* ro = nullptr;
        int l, r;
        int val;
        
        Node(int l, int r, int defaultVal = 0) : l(l), r(r), val(defaultVal) {}
    };
    
    Node* root;
    const int DEFAULT_VAL = 0;  // 默认值（求最大值时可以用INT_MIN）
    
    // 合并信息
    int mergeInfo(int a, int b) {
        return max(a, b);
    }
    
    // 维护节点
    void maintain(Node* o) {
        if (o->lo && o->ro) {
            o->val = mergeInfo(o->lo->val, o->ro->val);
        } else if (o->lo) {
            o->val = o->lo->val;
        } else if (o->ro) {
            o->val = o->ro->val;
        }
    }
    
    // 单点更新
    void update(Node* o, int i, int val) {
        if (o->l == o->r) {
            o->val = mergeInfo(o->val, val);
            return;
        }
        int m = o->l + (o->r - o->l) / 2;  // 避免溢出
        if (i <= m) {
            if (!o->lo) {
                o->lo = new Node(o->l, m, DEFAULT_VAL);
            }
            update(o->lo, i, val);
        } else {
            if (!o->ro) {
                o->ro = new Node(m + 1, o->r, DEFAULT_VAL);
            }
            update(o->ro, i, val);
        }
        maintain(o);
    }
    
    // 区间查询
    int query(Node* o, int l, int r) {
        if (!o || l > o->r || r < o->l) {
            return DEFAULT_VAL;
        }
        if (l <= o->l && o->r <= r) {
            return o->val;
        }
        int lRes = o->lo ? query(o->lo, l, r) : DEFAULT_VAL;
        int rRes = o->ro ? query(o->ro, l, r) : DEFAULT_VAL;
        return mergeInfo(lRes, rRes);
    }
    
    // 构造函数
    // l, r: 值域范围
    DynamicSegmentTree(int l, int r) {
        root = new Node(l, r, DEFAULT_VAL);
    }
    
    // 析构函数（释放内存）
    ~DynamicSegmentTree() {
        destroy(root);
    }
    
private:
    void destroy(Node* o) {
        if (o) {
            destroy(o->lo);
            destroy(o->ro);
            delete o;
        }
    }
};

/**
 * 动态开点延迟标记线段树
 * 支持区间修改的动态开点线段树
 */
struct DynamicLazySegmentTree {
    struct Node {
        Node* lo = nullptr;
        Node* ro = nullptr;
        int l, r;
        int sum;
        int todo;
        
        Node(int l, int r, int defaultVal = 0, int defaultTodo = 0) 
            : l(l), r(r), sum(defaultVal), todo(defaultTodo) {}
    };
    
    Node* root;
    const int DEFAULT_VAL = 0;
    const int DEFAULT_TODO = 0;
    
    int mergeInfo(int a, int b) {
        return a + b;
    }
    
    int mergeTodo(int a, int b) {
        return a + b;
    }
    
    void apply(Node* o, int f) {
        o->sum += (o->r - o->l + 1) * f;
        o->todo = mergeTodo(f, o->todo);
    }
    
    void maintain(Node* o) {
        o->sum = mergeInfo(
            o->lo ? o->lo->sum : DEFAULT_VAL,
            o->ro ? o->ro->sum : DEFAULT_VAL
        );
    }
    
    void spread(Node* o) {
        int m = o->l + (o->r - o->l) / 2;
        if (!o->lo) {
            o->lo = new Node(o->l, m, DEFAULT_VAL, DEFAULT_TODO);
        }
        if (!o->ro) {
            o->ro = new Node(m + 1, o->r, DEFAULT_VAL, DEFAULT_TODO);
        }
        if (int f = o->todo; f != DEFAULT_TODO) {
            apply(o->lo, f);
            apply(o->ro, f);
            o->todo = DEFAULT_TODO;
        }
    }
    
    void update(Node* o, int l, int r, int add) {
        if (l <= o->l && o->r <= r) {
            apply(o, add);
            return;
        }
        spread(o);
        int m = o->l + (o->r - o->l) / 2;
        if (l <= m) {
            update(o->lo, l, r, add);
        }
        if (m < r) {
            update(o->ro, l, r, add);
        }
        maintain(o);
    }
    
    int query(Node* o, int l, int r) {
        if (!o || l > o->r || r < o->l) {
            return DEFAULT_VAL;
        }
        if (l <= o->l && o->r <= r) {
            return o->sum;
        }
        spread(o);
        int lRes = query(o->lo, l, r);
        int rRes = query(o->ro, l, r);
        return mergeInfo(lRes, rRes);
    }
    
    DynamicLazySegmentTree(int l, int r) {
        root = new Node(l, r, DEFAULT_VAL, DEFAULT_TODO);
    }
    
    ~DynamicLazySegmentTree() {
        destroy(root);
    }
    
private:
    void destroy(Node* o) {
        if (o) {
            destroy(o->lo);
            destroy(o->ro);
            delete o;
        }
    }
};

/**
 * 可持久化线段树（主席树）
 * 支持历史版本查询
 * 
 * 使用示例：
 *   vector<int> a = {1, 2, 3, 4, 5};
 *   PersistentSegmentTree pst;
 *   vector<PSTNode*> versions;
 *   versions.push_back(pst.build(a, 0, a.size() - 1));
 *   versions.push_back(pst.modify(versions.back(), 0, 10));  // 在版本0基础上修改位置0为10
 *   int val = pst.queryRange(versions[1], 0, 2);  // 查询版本1的区间[0,2]
 */
struct PersistentSegmentTree {
    struct PSTNode {
        PSTNode* lo = nullptr;
        PSTNode* ro = nullptr;
        int l, r;
        int sum;
        
        PSTNode(int l, int r, int sum = 0) : l(l), r(r), sum(sum) {}
    };
    
    int mergeInfo(int a, int b) {
        return a + b;
    }
    
    // 构建初始版本
    PSTNode* build(const vector<int>& a, int l, int r) {
        PSTNode* o = new PSTNode(l, r);
        if (l == r) {
            o->sum = a[l];
            return o;
        }
        int m = (l + r) >> 1;
        o->lo = build(a, l, m);
        o->ro = build(a, m + 1, r);
        o->sum = mergeInfo(o->lo->sum, o->ro->sum);
        return o;
    }
    
    // 单点修改（创建新版本）
    PSTNode* modify(PSTNode* o, int i, int add) {
        PSTNode* newO = new PSTNode(o->l, o->r, o->sum);
        if (o->l == o->r) {
            newO->sum += add;
            return newO;
        }
        int m = (o->l + o->r) >> 1;
        if (i <= m) {
            newO->lo = modify(o->lo, i, add);
            newO->ro = o->ro;
        } else {
            newO->lo = o->lo;
            newO->ro = modify(o->ro, i, add);
        }
        newO->sum = mergeInfo(newO->lo->sum, newO->ro->sum);
        return newO;
    }
    
    // 区间查询
    int queryRange(PSTNode* o, int l, int r) {
        if (l <= o->l && o->r <= r) {
            return o->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (r <= m) {
            return queryRange(o->lo, l, r);
        }
        if (m < l) {
            return queryRange(o->ro, l, r);
        }
        int vl = queryRange(o->lo, l, r);
        int vr = queryRange(o->ro, l, r);
        return mergeInfo(vl, vr);
    }
    
    // 查询区间[l,r]中第k小的数（k从1开始）
    // 需要先对数组离散化，然后对每个前缀建立版本
    int kth(PSTNode* o, PSTNode* old, int k) {
        if (o->l == o->r) {
            return o->l;
        }
        int cntL = o->lo->sum - old->lo->sum;
        if (k <= cntL) {
            return kth(o->lo, old->lo, k);
        }
        return kth(o->ro, old->ro, k - cntL);
    }
    
    // 查询区间[l,r]中val的出现次数
    int query(PSTNode* o, PSTNode* old, int val) {
        if (o->l == o->r) {
            return o->sum - old->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (val <= m) {
            return query(o->lo, old->lo, val);
        }
        return query(o->ro, old->ro, val);
    }
    
    // 查询区间[l,r]中在[low,high]范围内的元素个数
    int countRange(PSTNode* o, PSTNode* old, int low, int high) {
        if (high < o->l || o->r < low) {
            return 0;
        }
        if (low <= o->l && o->r <= high) {
            return o->sum - old->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (high <= m) {
            return countRange(o->lo, old->lo, low, high);
        }
        if (m < low) {
            return countRange(o->ro, old->ro, low, high);
        }
        return countRange(o->lo, old->lo, low, high) + 
               countRange(o->ro, old->ro, low, high);
    }
};

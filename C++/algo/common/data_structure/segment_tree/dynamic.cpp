
#include <bits/stdc++.h>
using namespace std;
/**
 * https://oi-wiki.org/ds/seg/#%E5%8A%A8%E6%80%81%E5%BC%80%E7%82%B9%E7%BA%BF%E6%AE%B5%E6%A0%91
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
#include <bits/stdc++.h>
using namespace std;
/**
 * https://oi-wiki.org/ds/persistent-seg/
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
struct PersistentSegmentTree
{
    struct PSTNode
    {
        PSTNode *lo = nullptr;
        PSTNode *ro = nullptr;
        int l, r;
        int sum;

        PSTNode(int l, int r, int sum = 0) : l(l), r(r), sum(sum) {}
    };

    int mergeInfo(int a, int b)
    {
        return a + b;
    }

    // 构建初始版本
    PSTNode *build(const vector<int> &a, int l, int r)
    {
        PSTNode *o = new PSTNode(l, r);
        if (l == r)
        {
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
    PSTNode *modify(PSTNode *o, int i, int add)
    {
        PSTNode *newO = new PSTNode(o->l, o->r, o->sum);
        if (o->l == o->r)
        {
            newO->sum += add;
            return newO;
        }
        int m = (o->l + o->r) >> 1;
        if (i <= m)
        {
            newO->lo = modify(o->lo, i, add);
            newO->ro = o->ro;
        }
        else
        {
            newO->lo = o->lo;
            newO->ro = modify(o->ro, i, add);
        }
        newO->sum = mergeInfo(newO->lo->sum, newO->ro->sum);
        return newO;
    }

    // 区间查询
    int queryRange(PSTNode *o, int l, int r)
    {
        if (l <= o->l && o->r <= r)
        {
            return o->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (r <= m)
        {
            return queryRange(o->lo, l, r);
        }
        if (m < l)
        {
            return queryRange(o->ro, l, r);
        }
        int vl = queryRange(o->lo, l, r);
        int vr = queryRange(o->ro, l, r);
        return mergeInfo(vl, vr);
    }

    // 查询区间[l,r]中第k小的数（k从1开始）
    // 需要先对数组离散化，然后对每个前缀建立版本
    int kth(PSTNode *o, PSTNode *old, int k)
    {
        if (o->l == o->r)
        {
            return o->l;
        }
        int cntL = o->lo->sum - old->lo->sum;
        if (k <= cntL)
        {
            return kth(o->lo, old->lo, k);
        }
        return kth(o->ro, old->ro, k - cntL);
    }

    // 查询区间[l,r]中val的出现次数
    int query(PSTNode *o, PSTNode *old, int val)
    {
        if (o->l == o->r)
        {
            return o->sum - old->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (val <= m)
        {
            return query(o->lo, old->lo, val);
        }
        return query(o->ro, old->ro, val);
    }

    // 查询区间[l,r]中在[low,high]范围内的元素个数
    int countRange(PSTNode *o, PSTNode *old, int low, int high)
    {
        if (high < o->l || o->r < low)
        {
            return 0;
        }
        if (low <= o->l && o->r <= high)
        {
            return o->sum - old->sum;
        }
        int m = (o->l + o->r) >> 1;
        if (high <= m)
        {
            return countRange(o->lo, old->lo, low, high);
        }
        if (m < low)
        {
            return countRange(o->ro, old->ro, low, high);
        }
        return countRange(o->lo, old->lo, low, high) +
               countRange(o->ro, old->ro, low, high);
    }
};

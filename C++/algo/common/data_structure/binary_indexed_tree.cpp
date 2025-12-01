#include <bits/stdc++.h>
using namespace std;
// https://oi-wiki.org/ds/fenwick/
// Binary Indexed Tree (also known as Fenwick Tree) data structure
// 树状数组（Fenwick Tree），二叉索引树（Binary Index Tree, BIT）
// 树状数组 = 没有右子树的线段树
// https://en.wikipedia.org/wiki/Fenwick_tree
// 【推荐阅读】带你发明树状数组！https://leetcode.cn/problems/range-sum-query-mutable/solution/dai-ni-fa-ming-shu-zhuang-shu-zu-fu-shu-lyfll/
// 可视化 https://visualgo.net/zh/fenwicktree
// todo 从0到inf，超详细的树状数组详解 https://www.luogu.com.cn/article/6ewhbfs5
//  浅谈树状数组的优化及扩展 https://www.luogu.com.cn/article/790vjft4
//  浅谈树状数组套权值树 https://www.luogu.com.cn/article/8uekknpx
// https://oi-wiki.org/ds/bit/
// https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/FenwickTree.java.html
// 模板题
// LC307 https://leetcode.cn/problems/range-sum-query-mutable/
// https://www.luogu.com.cn/problem/P3374
// 问：给一堆区间，计算有多少对区间相交。
// 答：按右端点从小到大排序，这样之前遍历过的区间一定在左边。
//    然后查询 [l,r] 中有多少个之前遍历过的区间的右端点，即为在 [l,r] 左边的与 [l,r] 相交的区间个数。
//    至于其他的与 [l,r] 相交的区间，会在后续遍历中统计。
// https://codeforces.com/problemset/problem/1234/D 1600
// https://leetcode.cn/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// https://atcoder.jp/contests/arc075/tasks/arc075_c
// 静态区间种类 - 离线做法
//     https://www.luogu.com.cn/problem/P1972
//     https://atcoder.jp/contests/abc174/tasks/abc174_f
//     https://codeforces.com/problemset/problem/246/E 2400
//     https://codeforces.com/problemset/problem/594/D 2500
// 置换 LC2179 https://leetcode.cn/problems/count-good-triplets-in-an-array/
// - 同样的置换思想 LC1713 https://leetcode.cn/problems/minimum-operations-to-make-a-subsequence/
// 题目推荐 https://cp-algorithms.com/data_structures/fenwick.html#toc-tgt-12
// 树状数组的性质能使其支持动态 [1,x] 或 [x,n] 范围上的最值更新查询等操作
//     https://codeforces.com/problemset/problem/629/D
//     https://codeforces.com/problemset/problem/1635/F
// 好题 https://www.luogu.com.cn/problem/P2345 https://www.luogu.com.cn/problem/P5094
// 多变量统计 https://codeforces.com/problemset/problem/1194/E
//          T4 https://www.nowcoder.com/discuss/1022136
// 最多交换 k 次相邻字母后，得到的最小字典序
// - LC1505 https://leetcode.cn/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/
// LC2921 https://leetcode.cn/problems/maximum-profitable-triplets-with-increasing-prices-ii/
// https://codeforces.com/problemset/problem/1915/F 1500
// https://codeforces.com/problemset/problem/1234/D 1600
// https://atcoder.jp/contests/abc157/tasks/abc157_e 1443~CF1600
// https://codeforces.com/problemset/problem/627/B 1700 模板题
// https://codeforces.com/problemset/problem/652/D 1800 区间包含计数
// https://codeforces.com/problemset/problem/597/C 1900 长为 k 的上升子序列个数
// https://codeforces.com/problemset/problem/961/E 1900（不止一种做法）
// https://codeforces.com/problemset/problem/2042/D 1900
// https://codeforces.com/problemset/problem/629/D 2000
// https://codeforces.com/problemset/problem/1288/E 2000 转化
// https://codeforces.com/problemset/problem/1891/F 2000 离线 树 回溯
// https://codeforces.com/problemset/problem/165/D 2100
// https://codeforces.com/problemset/problem/703/D 2100 区间元素去重后的异或和
// - 联系 https://www.luogu.com.cn/problem/P1972
// https://codeforces.com/problemset/problem/1660/F2 2100 建模
// https://codeforces.com/problemset/problem/301/D 2200 整除对统计
// https://codeforces.com/problemset/problem/369/E 2200 区间统计技巧
// https://codeforces.com/problemset/problem/762/E 2200 离散化
// - https://codeforces.com/problemset/problem/1045/G 2200 同 762E
// https://codeforces.com/problemset/problem/1194/E 2200 多变量统计
// https://codeforces.com/problemset/problem/2065/H 2200
// https://codeforces.com/problemset/problem/628/E 2300 Z 形状个数
// - https://leetcode.cn/problems/max-black-square-lcci/ 相似题目
// https://codeforces.com/problemset/problem/1167/F 2300
// https://codeforces.com/problemset/problem/1967/C 2300
// https://codeforces.com/problemset/problem/12/D 2400 三维偏序
// https://codeforces.com/problemset/problem/246/E 2400
// https://codeforces.com/problemset/problem/1401/E 2400 线段把矩形分割成多少块
// https://codeforces.com/problemset/problem/594/D 2500
// https://codeforces.com/problemset/problem/992/E 2500 Nastya and King-Shamans  si <= sj * 2，这个不等式至多成立 O(log U) 次
// https://codeforces.com/problemset/problem/1334/F 2500
// https://codeforces.com/problemset/problem/1635/F 2800
// https://codeforces.com/problemset/problem/1446/F 3200
// https://atcoder.jp/contests/dp/tasks/dp_q 值域树状数组优化 DP
// https://atcoder.jp/contests/abc392/tasks/abc392_f 也可以用 Splay 树
// https://atcoder.jp/contests/abc256/tasks/abc256_f 多重前缀和
// https://atcoder.jp/contests/abc221/tasks/abc221_e
// https://atcoder.jp/contests/abc368/tasks/abc368_g
// https://www.lanqiao.cn/problems/5131/learning/?contest_id=144
// 贡献 https://www.lanqiao.cn/problems/12467/learning/?contest_id=167
// https://codeforces.com/gym/101649 I 题
// http://poj.org/problem?id=2155
// http://poj.org/problem?id=2886

struct BIT
{
    vector<int> tree;
    BIT(int N)
    {
        // (element count + 1, since indexing starts from 1)
        tree.assign(N + 1, 0);
    }

    int lowbit(int i)
    {
        return i & (-i);
    }

    void add(int index, int delta)
    {
        while (index < (int)tree.size())
        {
            tree[index] += delta;
            index += lowbit(index); // Move to parent node
        }
    }

    int query(int index)
    {
        int ans = 0;
        while (index > 0)
        {
            ans += tree[index];
            index -= lowbit(index); // Move to the previous node
        }
        return ans;
    }
};
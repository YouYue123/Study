#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/**
 * 静态「笛卡尔树 / Cartesian Tree」建树（竞赛里常口头叫 treap，但不是按优先级 split/merge 的随机 treap）。
 *
 * 性质（对 build 使用的 nums）：
 * - 中序遍历结点下标为 0,1,...,n-1，与原序列顺序一致。
 * - 堆性质：此处为大根堆，即父结点 u 满足 nums[u] >= nums[lc[u]]、nums[u] >= nums[rc[u]]（若子结点存在）。
 * - 时间复杂度 O(n)，单调栈实现。
 *
 * 典型使用场景：
 * 1) 区间最值与 LCA：在大根笛卡尔树上，原数组区间 [l,r] 的最大值所在下标 = 结点 l 与结点 r 的 LCA
 *    （小根堆建树则对应区间最小值）。常配合倍增 / 欧拉序 + RMQ 求 LCA。
 * 2) 子树对应连续区间：结点 i 的子树在中序上恰为一个连续下标区间，可做子树 DP、扫描线、分治。
 * 3) 建树本身用于理解 RMQ 结构，或作为线段树/单调栈思路的「树形」可视化。
 *
 * 约定：nums.size() >= 1；若 n==0 需调用方特判。
 */
struct Treap {
    vector<int> lc;  // 左孩子下标，-1 表示空
    vector<int> rc;  // 右孩子下标，-1 表示空

    /**
     * 根据 nums 建大根笛卡尔树，返回根下标（全局最大值的某个位置；互异时唯一）。
     * nums 按下标顺序即中序；相邻弹出时用「最后弹出」挂左孩子、「栈顶」挂右孩子，为标准线性算法。
     */
    int build(vector<ll>& nums) {
        int n = nums.size();
        lc.assign(n, -1);
        rc.assign(n, -1);
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int last = -1;
            // 栈底到栈顶 key 递减；遇到更大 nums[i] 时弹出较小者，它们进入 i 的左子树链
            while (!st.empty() && nums[st.back()] < nums[i]) {
                last = st.back();
                st.pop_back();
            }
            if (last != -1) lc[i] = last;
            if (!st.empty()) rc[st.back()] = i;
            st.push_back(i);
        }
        return st.front();  // 整棵树的根（最大值）
    }

    int get_left(int x) { return lc[x]; }
    int get_right(int x) { return rc[x]; }
};

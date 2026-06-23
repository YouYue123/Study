#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// https://oi-wiki.org/ds/cartesian-tree/
struct CartesianTree {
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

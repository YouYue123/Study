#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
struct Op {
    int id;
    int from;
    int to;
};
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
// dfs 定义: 将编号为 cur_layer 的盘子（及其上面的所有盘子）从 from 移到 to
// 递归的核心思想：总是将大问题拆解为“移动上面的部分”和“移动当前的盘子”
vector<Op> ops;
auto dfs = [&] (this auto&& dfs, int cur_layer, int from, int to) {
    if(cur_layer <= 0) return;
    int spare = 6 - from - to; // 利用数学技巧求出辅助柱: 1+2+3=6, spare = 6 - from - to
    // prev_layer 是当前盘子上面的盘子编号 (对应下标)
    // 代表当前目标盘子上方实际压着的盘子总数
    int prev_layer = cur_layer - 1;
    // 情况 1: 没有任何限制 (a[i] == 0)
    // 这就退化成了标准的汉诺塔问题：
    // 1. 把上面的所有盘子移到辅助柱
    // 2. 把当前盘子移到目标柱
    // 3. 把辅助柱上的盘子移到目标柱
    dfs(prev_layer, from, spare);
    ops.emplace_back(cur_layer, from, to);
    dfs(prev_layer, spare, to);
};
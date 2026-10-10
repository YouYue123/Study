#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
ll constexpr INF = 0x3f3f3f3f3f3f3f3f;
struct Op {
    int id;
    int from;
    int to;
};
void solve()
{
    int n;
    cin >> n;
    vector a(n, 0LL);
    for(int i = 0; i < n; i ++) cin >> a[i];

    // 预检查：如果某个盘子要求的上方层数超过了它本身上面的盘子数，则无解
    // 例如：第 i+1 层盘子上面只有 i 层，如果要求 a[i] > i，那肯定做不到
    for(int i = 0; i < n; i ++) {
        if(a[i] > i) {
            cout << "NO" << endl;
            return;
        }
    }
    vector<Op> ops;
    // dfs 定义: 将编号为 cur_layer 的盘子（及其上面的所有盘子）从 from 移到 to
    // 递归的核心思想：总是将大问题拆解为“移动上面的部分”和“移动当前的盘子”
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
        if(a[prev_layer] == 0) {
            // move prev_layer first if it can be moved
            dfs(prev_layer, from, spare);
            ops.emplace_back(cur_layer, from, to);
            dfs(prev_layer, spare, to);
        } else {
            // 情况 2: 存在限制 (a[i] > 0)
            // 意味着当前盘子上面必须保留 a[prev_layer] 个盘子才能移动
            // 计算需要被移开的盘子数量：
            // 我们只需要把多余的盘子移走，留下刚好 a[i] 个
            int target_layer = prev_layer - a[prev_layer];
            // 1. 先把上面不需要的“多余盘子”移到辅助柱
            dfs(target_layer, from, spare);
            // 2. 此时上面剩下的盘子数量刚好符合 a[i]，可以移动当前盘子了
            ops.emplace_back(cur_layer, from, to);
            // 3. 把之前移到辅助柱的多余盘子挪回原处(或者根据需要进行后续调整)
            dfs(target_layer, spare, from);
            // 4. 继续处理剩下的移动任务
            dfs(prev_layer, from , to);
        }
    };
    cout << "YES" << endl;
    dfs(n, 1, 3);
    cout << ops.size() << endl;
    for(auto& op : ops) {
        cout << op.id << " " << op.from << " " << op.to << endl;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
}